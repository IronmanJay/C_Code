#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
	/*记录某行，某位数字是否已经存在*/
	int raw[9][9] = { 0 };
	/*记录某列，某位数字是否已经存在*/
	int col[9][9] = { 0 };
	/*记录某3*3宫格内，某位数字是否已经存在*/
	int block[9][9] = { 0 };
	/*依次遍历二维数组每一个元素*/
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] != '.')
			{
				/*获取当前数字，这里-‘1’有两个作用，第一是使其成为int类型，第二是数组下标从0开始，所以对应-1*/
				int curNum = block[i][j] - '1';
				/*获取当前数字对应的块*/
				int blockIndex = i / 3 * 3 + j / 3;
				/*如果发现某行、某列、某块中有重复数字（判断依据是对应位置为true就是已经存在这个元素了），返回false，意味着存在重复元素*/
				if (raw[i][curNum] || col[j][curNum] || block[blockIndex][curNum])
				{
					return false;
				}
				/*否则说明当前元素是第一次出现，那么对应位置置为true，说明已经存在这个元素了*/
				else
				{
					raw[i][curNum] = 1;
					col[j][curNum] = 1;
					block[blockIndex][curNum] = 1;
				}
			}
		}
	}
	/*如果没有发现重复元素，返回true*/
	return true;
}

/*主函数省略*/
