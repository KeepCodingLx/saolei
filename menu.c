#define _CRT_SECURE_NO_WARNINGS   1

#include "game.h"

void menu()
{
	printf("****************************\n");
	printf("****************************\n");
	printf("*********1. play   *********\n");
	printf("*********0. exit   *********\n");
	printf("****************************\n");
	printf("****************************\n");
}
void game()
{
	//创建棋盘对应数组
	char mine[ROW][COL];//存放布置好雷的信息
	char show[ROWS][COLS];//存放排查出雷的信息

	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//打印棋盘
	DisplayBoard(show, ROW, COL);

	//布置雷
	SetMine(mine, ROW, COL, EASY_COUNT);

	//排查雷
	FindMine(mine, show, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择->\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏->\n");
			game();//开始游戏
			break;
		case 0:
			printf("退出游戏->\n");
			break;
		default:
			printf("选择错误，请重新选择->\n");
		}
	} while (input);
	return 0;
}
