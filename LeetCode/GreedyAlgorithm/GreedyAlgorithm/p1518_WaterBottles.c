#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int numWaterBottles(int numBottles, int numExchange)
{
	/*最终结果*/
	int res = 0;
	/*每轮的剩余空酒瓶，看还能换多少酒*/
	int emptyWine = 0;
	/*有酒就能喝*/
	while (numBottles > 0)
	{
		/*每轮只要有酒就能喝，所以结果加上每轮能喝的酒*/
		res += numBottles;
		/*每轮能喝多少酒就剩多少空酒瓶*/
		emptyWine += numBottles;
		/*每轮把所有的酒都喝没了，所以当前剩余的酒置空，同时为下一轮换酒做准备*/
		numBottles = 0;
		/*算空酒瓶能换多少酒*/
		numBottles += emptyWine / numExchange;
		/*算换完酒还剩多少空酒瓶*/
		emptyWine = emptyWine % numExchange;
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/
