#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/**
 * ��������������Ԫ��
 *
 * @param nums   ����������
 * @param index1 ����1
 * @param index2 ����2
 */
void swap(int* nums, int index1, int index2)
{
	int temp = nums[index1];
	nums[index1] = nums[index2];
	nums[index2] = temp;
}

void sortColors(int* nums, int numsSize)
{
	/*0�������е�����λ�ã�nums[0,zeroIndex] = 0*/
	int zeroIndex = 0;
	/*2�������е�����λ�ã�nums[twoIndex,nums.length-1] = 2*/
	int twoIndex = numsSize - 1;
	/**
	 * �������飬�Զ���i�ı仯������ע������ҪС��twoIndex����ΪtwoIndex����������仯
	 * ���仯�ģ���������õľͲ���Ҫ�����ˣ����Բ���С�ڵ������鳤��
	 */
	for (int i = 0; i <= twoIndex;)
	{
		/**
		 * ��Ϊ���������֣����Զ���1Ϊ��׼ֵ�������ǰԪ�ص��ڻ�׼��1��ֵ���鲻�����仯��
		 * nums[zeroIndex,twoIndex] = 1;
		 */
		if (nums[i] == 1)
		{
			i++;
		}
		/**
		 * �����ǰԪ�ص���0��˵��Ҫ�ŵ�����ߣ�����ע�⽻��֮��iҪ+1��+1��Ŀ���Ǳ�ֻ֤Ҫ����0����ָ��һ���ƶ���
		 * ����Ϊi�Ǵ�С��������˵��֮ǰ���Ѿ��ź����ˣ�����0->1������ô����1��i++��zeroIndex��++��
		 * ��֤����߽�������ֵ�϶���1����Ӱ������������������������αȽ�
		 */
		else if (nums[i] == 0)
		{
			swap(nums, i++, zeroIndex++);
		}
		/**
		 * �����ǰԪ�ص���2��˵��Ҫ�ŵ����ұߣ�����ע�⽻��֮��i�������仯��
		 * ��Ϊ�ұ߽���������ֵ�п��ܴ�Ҳ�п���С��������Ҫ���αȽ�
		 */
		else
		{
			swap(nums, i, twoIndex--);
		}
	}
}

/*������ʡ��*/