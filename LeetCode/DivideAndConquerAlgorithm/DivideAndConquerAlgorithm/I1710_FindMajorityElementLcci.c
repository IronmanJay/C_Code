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
int I1710countInRange(int* nums, int target, int left, int right)
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
 * ʹ�÷����㷨����ÿ���ֵ���ҪԪ��
 *
 * @param nums  ��������
 * @param left  ��ָ��
 * @param right ��ָ��
 * @return ��ǰ���ֵ���ҪԪ��
 */
int I1710majorityElementReturn(int* nums, int left, int right)
{
	/*����ֳ��˵���Ԫ�أ�ֱ�ӷ��أ���ʼ���Ρ�*/
	if (left == right)
	{
		return nums[left];
	}
	/*����ʹ�ö��ַ�����ʼ���֡�*/
	int mid = (right - left) / 2 + left;
	/*�ֱ������ҵݹ飬��ʼ���֡������ս�����ֳɵ���Ԫ��*/
	int leftNum = I1710majorityElementReturn(nums, left, mid);
	int rightNum = I1710majorityElementReturn(nums, mid + 1, right);
	/*����ֳɵ�ǰ���ֵ���Ԫ�أ����Ԫ��ֵ���ұ�Ԫ��ֵ��ȣ�˵����ǰ�׶ε������������Ԫ�أ����ؼ��ɣ���Ҳ�ǡ��Ρ�*/
	if (leftNum == rightNum)
	{
		return leftNum;
	}
	/*����ֳɵ�ǰ���ֵ���Ԫ����ߺ��ұ߲���ȣ���ô����Ҫ�ڵ�ǰ�����зֱ��ҵ����Գ��ֵĴ���*/
	int leftNumCount = I1710countInRange(nums, leftNum, left, mid);
	int rightNumCount = I1710countInRange(nums, rightNum, mid + 1, right);
	/*�����¼��ǰ���������һ�룬�����ǰԪ�س��ִ������ڵ�ǰ�����һ�룬��ô�϶�������������ҪԪ��*/
	int leftHalf = (mid - left) >> 1;
	int rightHalf = (right - (mid + 1)) >> 1;
	/*���������ж������������ǵ�ǰԪ�س��ֵĴ���Ҫ���ڵ�ǰ�����һ�룬��һ�������Ԫ�س��ֵĴ���Ҫ�����ұ�Ԫ�س��ֵĴ�����������߾��ǵ�ǰ�������ҪԪ��*/
	if (leftNumCount > leftHalf && leftNumCount > rightNumCount)
	{
		return leftNum;
	}
	/*�ұ��ж�ͬ��*/
	if (rightNumCount > rightHalf && leftNumCount < rightNumCount)
	{
		return rightNum;
	}
	/*��������£������Ԫ�س��ִ������ұ�Ԫ�س��ִ������ʱ����������Ԫ�ؾ��ɣ�������Ϊ�˱����������������[8,8,7,7,7]������������8����2�Σ��ұ�7����2�Σ����Ƴ��ִ���һ������ʵ���С������[8,8,7]���ұ�С������[7,7]���������ұ�С�����ǲ���ƽ�ģ���Ϊ��һ��7û���ȥ�����Ե����Ǹ������ʱ�������ұߵ�*/
	if (leftNumCount == rightNumCount)
	{
		return rightNum;
	}
	/*�����������������㣬����-1*/
	return -1;
}

int I1710majorityElement(int* nums, int numsSize)
{
	return I1710majorityElementReturn(nums, 0, numsSize - 1);
}

/*������ʡ��*/
