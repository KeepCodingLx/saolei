#define _CRT_SECURE_NO_WARNINGS   1

#include "game.h"

//��ʼ������
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


//��ӡ����
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


//��������
void SetMine(char mine[ROWS][COLS], int row, int col, int count)
{
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			//x,y��û���ף����Բ�����
			mine[x][y] = '1';
			count--;
		}
	}
}

//�Ų���
int GetMineCount(char mine[ROW][COL], int x, int y)//ͳ����Χ�׵ĸ���
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
		printf("������Ҫ�Ų�����꣡\n");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		//�������Ƿ�Ϸ�
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			//���ף�������Ϸ����
			if (mine[x][y] == '1')
			{
				printf("���ź������������ף���Ϸʧ�ܣ�\n");
				DisplayBoard(mine, row, col);
				break;
			}
			//�����ף�ͳ����Χ�׵ĸ���
			else
			{
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';//��ŵ��������ַ�
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
			printf("����Ƿ�������������\n");
	}
	if (win == row*col - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ���\n");
		DisplayBoard(mine, row, col);
	}
}
