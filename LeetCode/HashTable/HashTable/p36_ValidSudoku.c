#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
	/*��¼ĳ�У�ĳλ�����Ƿ��Ѿ�����*/
	int raw[9][9] = { 0 };
	/*��¼ĳ�У�ĳλ�����Ƿ��Ѿ�����*/
	int col[9][9] = { 0 };
	/*��¼ĳ3*3�����ڣ�ĳλ�����Ƿ��Ѿ�����*/
	int block[9][9] = { 0 };
	/*���α�����ά����ÿһ��Ԫ��*/
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] != '.')
			{
				/*��ȡ��ǰ���֣�����-��1�����������ã���һ��ʹ���Ϊint���ͣ��ڶ��������±��0��ʼ�����Զ�Ӧ-1*/
				int curNum = block[i][j] - '1';
				/*��ȡ��ǰ���ֶ�Ӧ�Ŀ�*/
				int blockIndex = i / 3 * 3 + j / 3;
				/*�������ĳ�С�ĳ�С�ĳ�������ظ����֣��ж������Ƕ�Ӧλ��Ϊtrue�����Ѿ��������Ԫ���ˣ�������false����ζ�Ŵ����ظ�Ԫ��*/
				if (raw[i][curNum] || col[j][curNum] || block[blockIndex][curNum])
				{
					return false;
				}
				/*����˵����ǰԪ���ǵ�һ�γ��֣���ô��Ӧλ����Ϊtrue��˵���Ѿ��������Ԫ����*/
				else
				{
					raw[i][curNum] = 1;
					col[j][curNum] = 1;
					block[blockIndex][curNum] = 1;
				}
			}
		}
	}
	/*���û�з����ظ�Ԫ�أ�����true*/
	return true;
}

/*������ʡ��*/
