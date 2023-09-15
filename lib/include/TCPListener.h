#pragma once

#include<string>
#include<winsock2.h>
#include<sstream>
#pragma comment(lib,"ws2_32.lib")

using namespace std;

#define SOCKET_LIBRARY_STARTUP_ERROR -1
#define LIBRARY_VERSION_MISMATCH -2
#define SOCKET_CREATE_FAILURE -3
#define SOCKET_BIND_FAILURE -4
#define START_LISTENER_FAILURE -5
#define HOSTNAME_UNAVAILABLE -6

#define HOST_INITIALIZED 0
#define CLIENT_CONNECTED 1
#define CLIENT_WAITRECEIVE 2

class TCPListener
{
	SOCKET sListener;//主机Server Socket
	sockaddr_in sAddr;//存放主机地址等相关信息

	SOCKET sClient;//Client的Socket，建立连接后自动生成
	sockaddr_in cAddr;//存放从机的相关信息
	
	string hostName;//存放主机名的字符串，用相关函数获取
	string hostIP;//存放主机IP的字符串
	int hostPort;//主机端口，自己设的。避免设为80等默认占用的端口

	HANDLE hReceive;

	int state;

	static DWORD WINAPI receiveThread(LPVOID lpParamter);
	static DWORD WINAPI waitConnectionThread(LPVOID lpParamter);

public:
	stringstream recvBuffer;//存放输入文字
    static bool tcpFlag ;

	TCPListener();
	TCPListener(int port);
	//int isAvailable() { return state; }
	int waitForClient();//等待Client连接函数

	int startWaitConnectionMultiThread();//多线程等待Client连接函数
	int stopWaitConnectionMultiThread();//停止等待Client连接

	int startReceiveOneLine(string& s);//开启阻塞接收，收到一句话后停止
	int transmit(string s);//发送
	int transmit(char* s, int length);

	int startReceiveMultiThread();//开启多线程接收，收到的东西直接输出
	int stopReceiveMultiThread();//停止接收线程

	int closeClient();

	int readState() { return state; }

	string displayHostIP() { return hostIP; }
	int displayHostPort(){ return hostPort; }
};