#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * addBinary(char * a, char * b) {
	/*获取字符串长度*/
	int lenA = strlen(a);
	int lenB = strlen(b);
	int i, j;
	/*表示进位*/
	int carry = 0;
	/*数组索引*/
	int index = 0;
	/*新建结果数组*/
	char *res = (char*)malloc(sizeof(char) * 1000);
	/*从后往前遍历*/
	for (i = lenA - 1, j = lenB - 1; i >= 0 || j >= 0 || carry; i--, j--)
	{
		/*有可能由于两数组长度不一样，就会有i，j小于0的情况，这时我们补零对齐即可*/
		int x = i < 0 ? 0 : a[i] - '0';
		int y = j < 0 ? 0 : b[j] - '0';
		/*对应位相加，另外根据carry判断是否进位，如果发生进位结果就是0，如果没发生进位结果就是1*/
		int num = (x + y + carry) % 2;
		/*carry只能得0或者1，如果发生进位就是1，如果没发生进位就是0*/
		carry = (x + y + carry) / 2;
		/*将结果存入数组*/
		res[index++] = num + '0';
	}
	/*结束字符*/
	res[index] = '\0';
	/*因为是从后向前遍历相加，所以需要翻转字符串数组才是结果*/
	for (i = 0, j = index - 1; i < j; i++, j--)
	{
		char temp = res[i];
		res[i] = res[j];
		res[j] = temp;
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/