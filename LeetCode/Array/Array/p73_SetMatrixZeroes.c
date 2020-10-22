#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
{
	/*��ȡ����*/
	int row = matrixSize;
	/*��ȡ����*/
	int col = matrixColSize[0];
	/*�жϵ�һ�У��У��Ƿ���0�ı�־λ����������Ƿ���Ҫ��Ϊ0*/
	bool rowFlag = false;
	bool colFlag = false;
	/*ɨ���һ�У��У��Ƿ���0*/
	for (int i = 0; i < col; i++) {
		if (matrix[0][i] == 0) {
			rowFlag = true;
			break;
		}
	}
	for (int i = 0; i < row; i++) {
		if (matrix[i][0] == 0) {
			colFlag = true;
			break;
		}
	}
	/*���±�[1,1]��ʼɨ�裬�����0���������еĵ�һ��Ԫ�غ������еĵ�һ��Ԫ����Ϊ0*/
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			if (matrix[i][j] == 0) {
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}
	/*
	  ɨ���һ�У��У��������0��˵���п����Ǳ������У��У�����0��������Ҫ����һ�У��У���Ϊ0
	  ����һ��������ǣ���һ�У��У�������0������Ҳ��Ҫ����һ�У��У���Ϊ0
	  ���Բ����Ǳ�������0����������0������Ҫ����һ�У��У���Ϊ0
	*/
	for (int i = 1; i < col; i++) {
		if (matrix[0][i] == 0) {
			for (int j = 0; j < row; j++) {
				matrix[j][i] = 0;
			}
		}
	}
	for (int i = 1; i < row; i++) {
		if (matrix[i][0] == 0) {
			for (int j = 0; j < col; j++) {
				matrix[i][j] = 0;
			}
		}
	}
	/*������һ��ʼ�ı�־λ�ж��Ƿ񽫵�һ�У��У���Ϊ0*/
	if (rowFlag) {
		for (int i = 0; i < col; i++) {
			matrix[0][i] = 0;
		}
	}
	if (colFlag) {
		for (int i = 0; i < row; i++) {
			matrix[i][0] = 0;
		}
	}
}

/*������ʡ��*/
