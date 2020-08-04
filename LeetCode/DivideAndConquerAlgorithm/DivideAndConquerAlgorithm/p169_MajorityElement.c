#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * ���ص�ǰ��������ĳ��Ԫ�س��ֵĴ���
 *
 * @param nums   ��������
 * @param target Ŀ��ֵ
 * @param left   ��ָ��
 * @param right  ��ָ��
 * @return ��ǰ��������target���ֵĴ���
 */
int p169countInRange(int* nums, int target, int left, int right)
{
	int count = 0;
	for (int i = left; i <= right; i++)
	{
		if (nums[i] == target)
		{
			count++;
		}
	}
	return count;
}

/**
 * ʹ�÷����㷨����ÿ���ֵ�����
 *
 * @param nums  ��������
 * @param left  ��ָ��
 * @param right ��ָ��
 * @return ��ǰ���ֵ�����
 */
int p169majorityElementReturn(int* nums, int left, int right)
{
	/*����ֳ��˵���Ԫ�أ�ֱ�ӷ��أ���ʼ���Ρ�*/
	if (left == right)
	{
		return nums[left];
	}
	/*����ʹ�ö��ַ�����ʼ���֡�*/
	int mid = (right - left) / 2 + left;
	/*�ֱ������ҵݹ飬��ʼ���֡������ս�����ֳɵ���Ԫ��*/
	int leftNum = p169majorityElementReturn(nums, left, mid);
	int rightNum = p169majorityElementReturn(nums, mid + 1, right);
	/*����ֳɵ�ǰ���ֵ���Ԫ�أ����Ԫ��ֵ���ұ�Ԫ��ֵ��ȣ�˵����ǰ�׶ε������������Ԫ�أ����ؼ��ɣ���Ҳ�ǡ��Ρ�*/
	if (leftNum == rightNum)
	{
		return leftNum;
	}
	/*����ֳɵ�ǰ���ֵ���Ԫ����ߺ��ұ߲���ȣ���ô����Ҫ�ڵ�ǰ�������ҵ�˭���ֵĴ�������ͷ���˭*/
	int leftNumCount = p169countInRange(nums, leftNum, left, mid);
	int rightNumCount = p169countInRange(nums, rightNum, mid + 1, right);
	/*�õ��Ľ��˭���ֵĴ�����ͷ���˭*/
	return leftNumCount > rightNumCount ? leftNum : rightNum;
}

int p169majorityElement(int* nums, int numsSize)
{
	return p169majorityElementReturn(nums, 0, numsSize - 1);
}

int main(void)
{
	/*������ʡ��*/
}