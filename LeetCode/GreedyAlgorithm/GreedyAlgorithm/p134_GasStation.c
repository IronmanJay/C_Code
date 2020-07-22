#include<stdio.h>
#include<stdlib.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
	/*全部油量差值*/
	int totalGas = 0;
	/*当前油量差值*/
	int curGas = 0;
	/*开始地址*/
	int startPos = 0;
	/*开始遍历*/
	for (int i = 0; i < gasSize; i++)
	{

		/*存储每一个“加油站”的存油量和耗油量差值*/
		totalGas += gas[i] - cost[i];
		/*存储当前“加油站的”存油量和耗油量差值*/
		curGas += gas[i] - cost[i];
		/*如果当前油量差值大于0，说明这个位置就有可能是起点，如果当前油量差值小于0，说明这个加油站肯定不是起点，因为不足以让汽车起步*/
		if (curGas < 0)
		{
			/*因为不是这个起点，所以起点从当前位置+1，看下一个位置是不是起点*/
			startPos = i + 1;
			/*curGas要置为0，因为这个点被舍弃了，所以从下一个重新开始*/
			curGas = 0;
		}
	}
	/*最后如果totalGas大于等于0，说明油量足够车跑完全程，那么直接返回startPos，如果小于0，说明所有的油加起来都不够车跑完全程，返回-1*/
	return totalGas >= 0 ? startPos : -1;
}

/*主函数省略*/
