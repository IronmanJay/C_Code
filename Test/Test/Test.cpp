#include<stdio.h>

void BubbleSort(int arr[],int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main(void)
{
	int arr[] = {9,9,5,8,2,6,2,4};
	BubbleSort(arr,sizeof(arr)/sizeof(arr[0]));
	for (int i = 0; i < 8; i++)
	{
		printf("%d\n",arr[i]);
	}
	getchar();
}
