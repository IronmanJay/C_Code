/*�رհ�ȫ��飬����strncpy��ʹ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*����������󳤶�*/
#define MAX_SIZE 10000

int* diffWaysToCompute(char * input, int* returnSize)
{
	/*�пշ���*/
	if (input == NULL || returnSize == NULL)
	{
		return NULL;
	}
	/*����ֵ��С��Ҳ���Կ���ָ��*/
	*returnSize = 0;
	/*���������*/
	int operatorCount = 0;
	/*��ȡ���鳤��*/
	int len = strlen(input);
	/*����ÿ��Ԫ������������൱�����ĸ��ڵ㣬ͳ�Ƹ���*/
	for (int i = 0; i < len; i++)
	{
		if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
			operatorCount++;
		}
	}
	/*���û���������˵��ȫ�����֣������ּ��뵽������鼴�ɣ���ʵ�ݹ����������ͺñȵ���Ҷ�ӽڵ㣬ֻ��һ�������뷵�ؼ��ɣ�׼�����ݽ������㣬���������յõ��������*/
	if (operatorCount == 0)
	{
		int* res = (int*)malloc(sizeof(int) * 1);
		res[0] = atoi(input);
		*returnSize = 1;
		return res;
	}
	/*�������������˵�����Խ�������*/
	else
	{
		/*�������*/
		int* res = (int*)malloc(MAX_SIZE * sizeof(int));
		/*���������������*/
		for (int i = 0; i < len; i++)
		{
			/*�ҵ���һ�������*/
			if (input[i] == '+' || input[i] == '-' || input[i] == '*')
			{
				/*������ǰ��׼���������и���������������*/
				char* leftStr = (char*)calloc(sizeof(char), i + 1);
				char* rightStr = (char*)calloc(sizeof(char), len - i);
				strncpy(leftStr, input, i);
				strncpy(rightStr, input + i + 1, len - i - 1);
				int leftSize;
				int rightSize;
				/*�����￪ʼ���Σ�������൱�ڸ��ڵ㣬ʹ�÷��ε�˼��ݹ��������������ֵ����������ֵ*/
				int* leftList = diffWaysToCompute(leftStr, &leftSize);
				int* rightList = diffWaysToCompute(rightStr, &rightSize);
				/*������һ�����飬��ʵÿ�εݹ�������ֻ������������������ֵ*/
				for (int left = 0; left < leftSize; left++)
				{
					for (int right = 0; right < rightSize; right++)
					{
						int a = leftList[left];
						int b = rightList[right];
						/*����������������㣬���뵽�������*/
						switch (input[i])
						{
						case '+':
							res[*returnSize] = a + b;
							break;
						case '-':
							res[*returnSize] = a - b;
							break;
						case '*':
							res[*returnSize] = a * b;
							break;
						}
						(*returnSize)++;
					}
				}
				/*�ͷ��ڴ�*/
				free(leftStr);
				free(rightStr);
				free(leftList);
				free(rightList);
			}
		}
		/*���ؽ��*/
		return res;
	}
}

/*������ʡ��*/
