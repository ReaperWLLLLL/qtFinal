#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include"TCPListener.h"

#include<iostream>
#include<string>
#include <windows.h> //Windows Multi-Thread
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")

using namespace std;

bool TCPListener::tcpFlag = true;

TCPListener::TCPListener(int port)
{
	hReceive = NULL;
	state = 0;
	hostPort = port;
	try
	{
		WORD w_req = MAKEWORD(2, 2);//Socket Library Version
		WSADATA wsadata;
		int err = WSAStartup(w_req, &wsadata);
		if (err != 0) {
			throw SOCKET_LIBRARY_STARTUP_ERROR;
		}
		//Check Library Version
		if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2) {
			WSACleanup();
			throw LIBRARY_VERSION_MISMATCH;
		}

		//Create Socket
		sListener = socket(AF_INET, SOCK_STREAM, 0);
		if (sListener == INVALID_SOCKET)
		{
			throw SOCKET_CREATE_FAILURE;
		}
		//Create Listener
		sAddr.sin_family = AF_INET;
		sAddr.sin_port = htons(hostPort);
		sAddr.sin_addr.S_un.S_addr = INADDR_ANY;
		if (::bind(sListener, (LPSOCKADDR)&sAddr, sizeof(sAddr)) == SOCKET_ERROR)
		{
			cout << "Failed bind()" << endl;
			throw SOCKET_BIND_FAILURE;
		}
		if (::listen(sListener, 2) == SOCKET_ERROR)
		{
			cout << "Failed listen()" << endl;
			throw START_LISTENER_FAILURE;
		}
		//Get Host Name
		TCHAR strName[100];
		DWORD nSize = 100;
		::GetComputerName(strName, &nSize);
		char descBuf[200] = { 0 };
		sprintf_s(descBuf, "%S", strName);
		hostName = descBuf;
		//Get Host IP Address for Connection
		hostent* lv_pHostent;
		lv_pHostent = (hostent*)malloc(sizeof(hostent));
		if (NULL == (lv_pHostent = gethostbyname(descBuf)))
		{
			cout << "Get Hosrname Failed." << endl;
			throw HOSTNAME_UNAVAILABLE;
		}
		SOCKADDR_IN lv_sa;
		lv_sa.sin_family = AF_INET;
		lv_sa.sin_port = htons(6000);
		memcpy(&lv_sa.sin_addr.S_un.S_addr, lv_pHostent->h_addr_list[0], lv_pHostent->h_length);
		//	free(lv_pHostent);
		hostIP = inet_ntoa(lv_sa.sin_addr);
		state = HOST_INITIALIZED;
	}
	catch (int err)
	{
		state = err;
		cout << err << endl;
	}
}

TCPListener::TCPListener()
{
	new(this)TCPListener(8888);
}

int TCPListener::waitForClient()
{
	if (state != HOST_INITIALIZED)return -1;

	int nAddrLen = sizeof(cAddr);
	char szText[] = "TCP Server Demo! \r\n";
	while (TRUE)
	{
		sClient = accept(sListener, (SOCKADDR*)&cAddr, &nAddrLen);
		if (sClient > 0)
		{
			break;
		}
	}
	state = CLIENT_CONNECTED;
	return 0;
}

int TCPListener::startReceiveOneLine(string& s)
{
	if (state != CLIENT_CONNECTED)return -1;
	char recvbuf[200] = {};
	int iResult=0;
	iResult = recv(sClient, recvbuf, 200, 0);
	s = recvbuf;
	return iResult;
}

DWORD WINAPI TCPListener::waitConnectionThread(LPVOID lpParamter)
{
	TCPListener* pObj = (TCPListener*)lpParamter;
	int nAddrLen = sizeof(pObj->cAddr);
	while (1)
	{
		pObj->sClient = accept(pObj->sListener, (SOCKADDR*)&pObj->cAddr, &nAddrLen);
		if (pObj->sClient > 0)
		{
			break;
		}
	}
	pObj->state = CLIENT_CONNECTED;
	return 0;
}

int TCPListener::startWaitConnectionMultiThread()
{
	if (state != HOST_INITIALIZED)return -1;
	recvBuffer.clear();
	hReceive = CreateThread(NULL, 0, TCPListener::waitConnectionThread, this, 0, NULL);
    //state = CLIENT_CONNECTED;
    return 0;
}


int TCPListener::stopWaitConnectionMultiThread()
{
	if (state != CLIENT_CONNECTED)return -1;
	TerminateThread(hReceive, 0);
	state = HOST_INITIALIZED;
	//	cout << recvBuffer.str();
    return 0;
}

DWORD WINAPI TCPListener::receiveThread(LPVOID lpParamter)
{
	TCPListener* pObj = (TCPListener*)lpParamter;
	while (1)
	{
		char recvbuf[20001] = {};
		int iResult = 0;
		//iResult = recv(pObj->sClient, recvbuf, 20000, 0);
		//读入ssrteam
		int x = 0;
		if ((x = recv(pObj->sClient, recvbuf, 20000, 0)) < 0)
		{
			return -1;
		}
		else if (x > 0)//说明此处的数据尚未接收完毕，继续往流对象中添加！！
		{
			pObj->recvBuffer << recvbuf;
			cout << recvbuf;
		}
	}
	return 0;
}

int TCPListener::startReceiveMultiThread()
{
	if (state != CLIENT_CONNECTED)return -1;

	recvBuffer.clear();
	hReceive= CreateThread(NULL, 0, TCPListener::receiveThread, this, 0, NULL);
	state = CLIENT_WAITRECEIVE;
    return 0;
}


int TCPListener::stopReceiveMultiThread()
{
	if (state != CLIENT_WAITRECEIVE)return -1;
	TerminateThread(hReceive, 0);
	state = CLIENT_CONNECTED;
//	cout << recvBuffer.str();
    return 0;
}

int TCPListener::transmit(string s)
{
	if (state != CLIENT_CONNECTED)return -1;
	return send(sClient, s.c_str(), s.length(), 0);
    return 0;
}

int TCPListener::transmit(char* s, int length)
{
	if (state != CLIENT_CONNECTED)return -1;
	return send(sClient, s, length, 0);

    return 0;
}

int TCPListener::closeClient()
{
	if (state != CLIENT_CONNECTED)return -1;
	::closesocket(sClient);
	return 0;
}