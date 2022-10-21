#define _CRT_SECURE_NO_WARNINGS   1

#include "game.h"

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}


//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("------------------\n");
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("------------------\n");
}


//布置棋盘
void SetMine(char mine[ROWS][COLS], int row, int col, int count)
{
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			//x,y处没有雷，可以布置雷
			mine[x][y] = '1';
			count--;
		}
	}
}

//排查雷
int GetMineCount(char mine[ROW][COL], int x, int y)//统计周围雷的个数
{
	return    (mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] +
		mine[x + 1][y - 1] -
		8 * '0');
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	while (win<row*col - EASY_COUNT)
	{
		printf("请输入要排查的坐标！\n");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		//该坐标是否合法
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			//是雷，宣告游戏结束
			if (mine[x][y] == '1')
			{
				printf("很遗憾，您触碰了雷，游戏失败！\n");
				DisplayBoard(mine, row, col);
				break;
			}
			//不是雷，统计周围雷的个数
			else
			{
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';//存放的是数字字符
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
			printf("坐标非法！请重新输入\n");
	}
	if (win == row*col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功！\n");
		DisplayBoard(mine, row, col);
	}
}
