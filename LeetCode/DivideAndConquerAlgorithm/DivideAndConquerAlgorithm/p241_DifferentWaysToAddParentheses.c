/*关闭安全检查，方便strncpy的使用*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*设置数组最大长度*/
#define MAX_SIZE 10000

int* diffWaysToCompute(char * input, int* returnSize)
{
	/*判空返回*/
	if (input == NULL || returnSize == NULL)
	{
		return NULL;
	}
	/*返回值大小，也可以看作指针*/
	*returnSize = 0;
	/*运算符个数*/
	int operatorCount = 0;
	/*获取数组长度*/
	int len = strlen(input);
	/*遍历每个元素找运算符，相当于树的根节点，统计个数*/
	for (int i = 0; i < len; i++)
	{
		if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
			operatorCount++;
		}
	}
	/*如果没有运算符，说明全是数字，将数字加入到结果数组即可，其实递归遍历到这里就好比到了叶子节点，只有一个数加入返回即可，准备回溯进行运算，层层回溯最终得到整个结果*/
	if (operatorCount == 0)
	{
		int* res = (int*)malloc(sizeof(int) * 1);
		res[0] = atoi(input);
		*returnSize = 1;
		return res;
	}
	/*否则有运算符，说明可以进行运算*/
	else
	{
		/*结果数组*/
		int* res = (int*)malloc(MAX_SIZE * sizeof(int));
		/*遍历数组找运算符*/
		for (int i = 0; i < len; i++)
		{
			/*找到了一个运算符*/
			if (input[i] == '+' || input[i] == '-' || input[i] == '*')
			{
				/*做分治前的准备工作，切割左子树和右子树*/
				char* leftStr = (char*)calloc(sizeof(char), i + 1);
				char* rightStr = (char*)calloc(sizeof(char), len - i);
				strncpy(leftStr, input, i);
				strncpy(rightStr, input + i + 1, len - i - 1);
				int leftSize;
				int rightSize;
				/*从这里开始分治，运算符相当于根节点，使用分治的思想递归遍历求左子树的值和右子树的值*/
				int* leftList = diffWaysToCompute(leftStr, &leftSize);
				int* rightList = diffWaysToCompute(rightStr, &rightSize);
				/*看似是一个数组，其实每次递归这里面只有左子树和右子树的值*/
				for (int left = 0; left < leftSize; left++)
				{
					for (int right = 0; right < rightSize; right++)
					{
						int a = leftList[left];
						int b = rightList[right];
						/*根据运算符进行运算，加入到结果数组*/
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
				/*释放内存*/
				free(leftStr);
				free(rightStr);
				free(leftList);
				free(rightList);
			}
		}
		/*返回结果*/
		return res;
	}
}

/*主函数省略*/
