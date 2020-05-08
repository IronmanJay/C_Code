#pragma once

#define WIDE 60
#define HIGH 20

struct BODY
{
	int X;
	int Y;
};

struct SNAKE
{
	int size;
	struct BODY body[WIDE*HIGH];
}snake;

int food[2] = { 0 };

int score = 0;

//Æ«ÒÆ×ø±ê
int dx = 0;
int dy = 0;

//¼ÇÂ¼ÉßÄ©Î²×ø±ê
int lx = 0;
int ly = 0;

void InitFood();

void InitSnake();

void ShowUI();

void PlayGame();

void InitWall();