#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
	/*�½��������*/
	int* res = (int *)malloc(sizeof(int) * 2);
	/*����ÿһ��ֵ�����������������Ҫ��ľ��˳�forѭ��������˵��һ����������*/
	for (int i = 0; i < numbersSize; i++)
	{
		/*
			����low = i + 1����Ϊ����Ҫ�������һ��Ԫ�ؿ�ʼ�̶���
			�Ӻ�����������target�͹̶�ֵ�Ĳ�ֵ���ͱ���˶��ֲ��������������
		*/
		int low = i + 1;
		/*���ֲ���β���̶����������鳤��*/
		int high = numbersSize - 1;
		/*�����м�ֵ����*/
		while (low <= high)
		{
			/*�����м�ֵ����*/
			int mid = (high - low) / 2 + low;
			/*
				����ڳ�ȥ�̶�ֵ�������У����ҵ���target�͹̶�ֵ�Ĳ�ֵ��˵���̶�ֵ+��ǰ���ֵ����Ŀ��ֵ��
				��Ϊ��������˵��index1<index2������Ҫ�󣬷����±꼴�ɣ�����Ҫ�󣬷ֱ�+1
			*/
			if (numbers[mid] == target - numbers[i])
			{
				res[0] = i + 1;
				res[1] = mid + 1;
				*returnSize = 2;
				return res;
			}
			/*����ڳ�ȥ�̶�ֵ�������У������м�ֵ����target�͹̶�ֵ�Ĳ�ֵ��˵������Ҫ�ҵ����м�ֵ��ߣ��������*/
			else if (numbers[mid] > target - numbers[i])
			{
				high = mid - 1;
			}
			/*����ڳ�ȥ�̶�ֵ�������У������м�ֵС��target�͹̶�ֵ�Ĳ�ֵ��˵������Ҫ�ҵ����м�ֵ�ұߣ����Ҳ���*/
			else
			{
				low = mid + 1;
			}
		}
	}
	/*���û�ҵ�������-1����*/
	*returnSize = 2;
	return res;
}

/*������ʡ��*/
