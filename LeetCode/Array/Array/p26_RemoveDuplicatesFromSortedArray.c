#include<stdio.h>
#include<stdlib.h>

int removeDuplicates(int* nums, int numsSize) 
{
	/*���������ֱ�ӷ���*/
	if (numsSize == 0 || nums == NULL)
	{
		return numsSize;
	}
	/*�������ָ��*/
	int slowIndex = 0; /*��ָ����Ҫ�����ǶԱ�Ԫ���Ƿ���Ⱥ�Ԥ������ȵ�Ԫ��λ��*/
	int quickIndex = 1; /*��ָ�����Ҫ�����ǶԱ�Ԫ���Ƿ���Ⱥͱ�����������*/
	/*ѭ����������*/
	while (quickIndex < numsSize)
	{
		/*������ֵ��ȵ�ʱ�����ǲ�������������ʹ��ָ����ǰ�ߣ�������ǰԪ�أ�������Ŀ�����ҳ����е��ظ�Ԫ��*/
		if (nums[slowIndex] == nums[quickIndex])
		{
			quickIndex++;
		}
		/*�������ֵ����ȣ���ô��ָ���+1��ֻ+1��Ԥ��һ��λ�ø�����ȵ�Ԫ�أ���Ϊ��������ֱ�ӽ���һ������ȵ�Ԫ�طŵ���ָ��ָ��λ�ã�Ȼ���ָ�����ѭ��*/
		else
		{
			slowIndex++;
			nums[slowIndex] == nums[quickIndex];
			quickIndex++;
		}
	}
	/*���ؽ��*/
	return slowIndex + 1;
}

int main(void)
{
	/*������ʡ��*/
}
