#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<WinSock2.h> // 包含网络编程的头文件，引入静态库
#pragma comment(lib, "ws2_32.lib")

// 检查函数返回值，如果出错则打印错误信息
int merror(int redata,int error,char* showinfo)
{
	if (redata == error)
	{
		perror(showinfo);
		getchar();
		return -1;
	}
	return 0;
}

// 将html文件返回给客户端
void sendHtml(SOCKET s,char *filename)
{
	// 打开文件
	FILE *pFile = fopen(filename, "r");
	if (pFile == NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	char temp[1024] = "";
	do
	{
		// 将文件内容读取到缓冲区
		fgets(temp, 1024, pFile);
		// 将缓冲区中的数据发送到客户端
		send(s, temp, strlen(temp), 0);
	} while (!feof(pFile));
	fclose(pFile);
}

int main()
{
	printf("欢迎使用Http服务器\n");
	WSADATA wsData;
	int isok = WSAStartup(MAKEWORD(2,2),&wsData); // 确定socket版本信息
	merror(isok, WSAEINVAL, "申请socket失败\n");
	/*
		AF_INET表示使用IPv4地址，也被称为协议族，决定socket的地址类型
		SOCK_STREAM表示传输类型为流传输
		IPPROTO_TCP表示指定的传输协议为TCP
	*/
	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	merror(server, INVALID_SOCKET, "创建socket失败\n");
	struct sockaddr_in seraddr;
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(80); // 网络中的数据和电脑上的数据存储是有区别的，网络是大端存储，PC是小端存储
	seraddr.sin_addr.s_addr = INADDR_ANY; // 监听任意地址
	isok = bind(server, (struct sockaddr*)&seraddr, sizeof(seraddr));
	merror(isok, SOCKET_ERROR, "绑定失败\n");
	isok = listen(server, 5);
	merror(isok, SOCKET_ERROR, "监听失败\n");
	struct sockaddr_in claddr;
	int cllen = sizeof(claddr);
	while (1)
	{
		SOCKET client = accept(server, (struct sockaddr*)&claddr, &cllen);
		merror(client, INVALID_SOCKET, "连接失败\n");
		char revData[1024] = "";
		recv(client, revData, 1024, 0);
		printf("%s共接收到%d字节数据\n", revData, strlen(revData));
		char *filename = "D:\\Software\\C_Code\\HTTPServer\\Resource\\index.html";
		sendHtml(client, filename);
		closesocket(client);
	}
	closesocket(server);
	WSACleanup();
	getchar();
	return 0;
}
