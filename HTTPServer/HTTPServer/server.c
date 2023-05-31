#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<WinSock2.h> // ���������̵�ͷ�ļ������뾲̬��
#pragma comment(lib, "ws2_32.lib")

// ��麯������ֵ������������ӡ������Ϣ
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

// ��html�ļ����ظ��ͻ���
void sendHtml(SOCKET s,char *filename)
{
	// ���ļ�
	FILE *pFile = fopen(filename, "r");
	if (pFile == NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	char temp[1024] = "";
	do
	{
		// ���ļ����ݶ�ȡ��������
		fgets(temp, 1024, pFile);
		// ���������е����ݷ��͵��ͻ���
		send(s, temp, strlen(temp), 0);
	} while (!feof(pFile));
	fclose(pFile);
}

int main()
{
	printf("��ӭʹ��Http������\n");
	WSADATA wsData;
	int isok = WSAStartup(MAKEWORD(2,2),&wsData); // ȷ��socket�汾��Ϣ
	merror(isok, WSAEINVAL, "����socketʧ��\n");
	/*
		AF_INET��ʾʹ��IPv4��ַ��Ҳ����ΪЭ���壬����socket�ĵ�ַ����
		SOCK_STREAM��ʾ��������Ϊ������
		IPPROTO_TCP��ʾָ���Ĵ���Э��ΪTCP
	*/
	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	merror(server, INVALID_SOCKET, "����socketʧ��\n");
	struct sockaddr_in seraddr;
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(80); // �����е����ݺ͵����ϵ����ݴ洢��������ģ������Ǵ�˴洢��PC��С�˴洢
	seraddr.sin_addr.s_addr = INADDR_ANY; // ���������ַ
	isok = bind(server, (struct sockaddr*)&seraddr, sizeof(seraddr));
	merror(isok, SOCKET_ERROR, "��ʧ��\n");
	isok = listen(server, 5);
	merror(isok, SOCKET_ERROR, "����ʧ��\n");
	struct sockaddr_in claddr;
	int cllen = sizeof(claddr);
	while (1)
	{
		SOCKET client = accept(server, (struct sockaddr*)&claddr, &cllen);
		merror(client, INVALID_SOCKET, "����ʧ��\n");
		char revData[1024] = "";
		recv(client, revData, 1024, 0);
		printf("%s�����յ�%d�ֽ�����\n", revData, strlen(revData));
		char *filename = "D:\\Software\\C_Code\\HTTPServer\\Resource\\index.html";
		sendHtml(client, filename);
		closesocket(client);
	}
	closesocket(server);
	WSACleanup();
	getchar();
	return 0;
}
