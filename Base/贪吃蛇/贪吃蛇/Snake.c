#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>
#include"Snake.h"

void InitFood()
{
	food[0] = rand() % WIDE;
	food[1] = rand() % HIGH;
}

void InitSnake()
{
	snake.size = 2;
	snake.body[0].X = WIDE / 2;
	snake.body[0].Y = HIGH / 2;
	snake.body[1].X = WIDE / 2 - 1;
	snake.body[1].Y = HIGH / 2;
}

void ShowUI()
{
	COORD coord;
	//更新末尾空格
	coord.X = lx;
	coord.Y = ly;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');
	//显示蛇的位置
	for (int i = 0; i < snake.size; i++)
	{
		coord.X = snake.body[i].X;
		coord.Y = snake.body[i].Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		if (i == 0) 
		{
			putchar('@');
		}
		else {
			putchar('*');
		}
	}
	//显示食物位置
	coord.X = food[0];
	coord.Y = food[1];
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('#');
}

void PlayGame()
{
	char key = 'D';
	while (snake.body[0].X >= 0 && snake.body[0].X < WIDE 
		&& snake.body[0].Y >= 0 && snake.body[0].Y < HIGH)
	{
		//显示墙
		//InitWall();
		//显示界面
		ShowUI();
		//方向控制
		while (_kbhit())
		{
			key = _getch();
		}
		switch (key)
		{
		case 'D':case'd':dx = 1, dy = 0; break;
		case 'A':case'a':dx = -1, dy = 0; break;
		case 'W':case'w':dx = 0, dy = -1; break;
		case 'S':case's':dx = 0, dy = 1; break;

		}
		//是否和自身碰撞
		for (int i = 1; i < snake.size; i++)
		{
			if (snake.body[0].X == snake.body[i].X && snake.body[0].Y == snake.body[i].Y)
			{
				return;
			}
		}
		//是否和食物碰撞
		if (snake.body[0].X == food[0] && snake.body[0].Y == food[1])
		{
			//随机新食物
			InitFood();
			//蛇身体增长
			snake.size++;
			//分数的增长
			score += 10;
		}
		//蛇更新坐标
		lx = snake.body[snake.size - 1].X;
		ly = snake.body[snake.size - 1].Y;
		for (int i = snake.size-1; i > 0; i--)
		{
			snake.body[i].X = snake.body[i - 1].X;
			snake.body[i].Y = snake.body[i - 1].Y;
		}
		//更新蛇头
		snake.body[0].X += dx;
		snake.body[0].Y += dy;
		//设置速度
		Sleep(200);
		//清屏
		//system("cls");
	}
}

void InitWall()
{
	for (int i = 0; i <= HIGH; i++)
	{
		for (int j = 0; j <= WIDE; j++)
		{
			if (i == HIGH)
			{
				putchar('=');
			}
			else if (j == WIDE)
			{
				putchar('=');
			}
			else {
				putchar(' ');
			}
		}
		putchar('\n');
	}
}

int main(void)
{
	srand((size_t)time(NULL));
	//去掉光标
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	InitWall();
	InitFood();
	InitSnake();
	PlayGame();
	getchar();
}
