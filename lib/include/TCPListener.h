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
	SOCKET sListener;//����Server Socket
	sockaddr_in sAddr;//���������ַ�������Ϣ

	SOCKET sClient;//Client��Socket���������Ӻ��Զ�����
	sockaddr_in cAddr;//��Ŵӻ��������Ϣ
	
	string hostName;//������������ַ���������غ�����ȡ
	string hostIP;//�������IP���ַ���
	int hostPort;//�����˿ڣ��Լ���ġ�������Ϊ80��Ĭ��ռ�õĶ˿�

	HANDLE hReceive;

	int state;

	static DWORD WINAPI receiveThread(LPVOID lpParamter);
	static DWORD WINAPI waitConnectionThread(LPVOID lpParamter);

public:
	stringstream recvBuffer;//�����������
    static bool tcpFlag ;

	TCPListener();
	TCPListener(int port);
	//int isAvailable() { return state; }
	int waitForClient();//�ȴ�Client���Ӻ���

	int startWaitConnectionMultiThread();//���̵߳ȴ�Client���Ӻ���
	int stopWaitConnectionMultiThread();//ֹͣ�ȴ�Client����

	int startReceiveOneLine(string& s);//�����������գ��յ�һ�仰��ֹͣ
	int transmit(string s);//����
	int transmit(char* s, int length);

	int startReceiveMultiThread();//�������߳̽��գ��յ��Ķ���ֱ�����
	int stopReceiveMultiThread();//ֹͣ�����߳�

	int closeClient();

	int readState() { return state; }

	string displayHostIP() { return hostIP; }
	int displayHostPort(){ return hostPort; }
};