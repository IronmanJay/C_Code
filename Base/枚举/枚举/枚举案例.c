#include<stdio.h>

enum TYPE
{
	run,attack,skill,dance,showUI,frozen,dizz,dath,moti
}type;

int main02(void)
{
	int value;
	while (1)
	{
		scanf_s("%d", &value);
		switch (value)
		{
		case run:
			printf("正在移动中\n");
			break;
		case attack:
			printf("正在攻击中\n");
			break;
		case skill:
			printf("正在释放技能中\n");
			break;
		case dance:
			printf("正在跳舞中\n");
			break;
		case showUI:
			printf("正在显示徽章中\n");
			break;
		case frozen:
			printf("正在冰冻中\n");
			break;
		case dizz:
			printf("正在眩晕中\n");
			break;
		case dath:
			printf("正在死亡中\n");
			return 0;
			break;
		case moti:
			printf("正在静止中\n");
			break;
		default:
			break;
		}
	}
	getchar();
}