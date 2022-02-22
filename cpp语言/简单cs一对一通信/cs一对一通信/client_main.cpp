
#include <WinSock2.h>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA wsaData;
	SOCKET s;
	SOCKADDR_IN ServerAddr;
	int Port = 5150;

	WSAStartup(MAKEWORD(2, 2), &wsaData);                                     //初始化Windows Socket 2.2      
	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);                           // 创建一个新的Socket来连接服务器  

	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(Port);
	ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");                                //在程序中我与本机进行通信
	int result = connect(s, (SOCKADDR *)&ServerAddr, sizeof(ServerAddr));   // 向服务器发出连接请求
	if (result == 0){                                                                                                //result==0表示连接成功
		cout << "Client has connected to server!";
	}

	closesocket(s);
	WSACleanup();

	return 0;
}