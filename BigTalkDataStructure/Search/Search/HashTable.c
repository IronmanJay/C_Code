#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /*�洢�ռ��ʼ������*/
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 /*����ɢ�б�Ϊ����ĳ���*/
#define NULLKEY -32768

typedef int Status; /*Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��*/

typedef struct
{
	int *elem; /*����Ԫ�ش洢���ʣ���̬��������*/
	int count; /*��ǰ����Ԫ�ظ���*/
}HashTable;

int m = 0; /*ɢ�б����ȫ�ֱ���*/

/*��ʼ��ɢ�б�*/
Status InitHashTable(HashTable *H)
{
	int i;
	m = HASHSIZE;
	H->count = m;
	H->elem = (int *)malloc(m * sizeof(int));
	for (i = 0; i < m; i++)
	{
		H->elem[i] = NULLKEY;
	}
	return OK;
}

/*ɢ�к���*/
int Hash(int key)
{
	return key % m; /*����������*/
}

/*����ؼ��ֽ�ɢ�б�*/
void InsertHash(HashTable *H, int key)
{
	int addr = Hash(key); /*��ɢ�е�ַ*/
	while (H->elem[addr] != NULLKEY) /*�����Ϊ�գ����ͻ*/
	{
		addr = (addr + 1) % m; /*���Ŷ�ַ��������̽��*/
	}
	H->elem[addr] = key; /*ֱ���п�λ�����ؼ���*/
}

/*ɢ�б���ҹؼ���*/
Status SearchHash(HashTable H, int key, int *addr)
{
	*addr = Hash(key); /*��ɢ�е�ַ*/
	while (H.elem[*addr] != key)
	{
		*addr = (*addr + 1) % m; /*���Ŷ�ַ������̽��*/
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) /*���ѭ���ص�ԭ��*/
		{
			return UNSUCCESS;
		}
	}
	return SUCCESS;
}

/*ɢ�б�*/
int mainHashTable(void)
{

	int arr[HASHSIZE] = { 12,67,56,16,25,37,22,29,15,47,48,34 };
	int i, p, key, result;
	HashTable H;
	key = 39;

	/*��ʼ��ɢ�б�*/
	InitHashTable(&H);
	/*�����ݲ���ɢ�б�*/
	for (i = 0; i < m; i++)
	{
		InsertHash(&H, arr[i]);
	}

	/*����һ�������ڵ�����*/
	result = SearchHash(H, key, &p);
	if (result)
	{
		printf("���� %d �ĵ�ַΪ��%d \n", key, p);
	}
	else
	{
		printf("���� %d ʧ�� \n", key);
	}

	/*����ÿһ������*/
	for (i = 0; i < m; i++)
	{
		key = arr[i];
		SearchHash(H, key, &p);
		printf("���� %d �ĵ�ַΪ��%d \n", key, p);
	}

	getchar();

}
