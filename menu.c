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
	//�������̶�Ӧ����
	char mine[ROW][COL];//��Ų��ú��׵���Ϣ
	char show[ROWS][COLS];//����Ų���׵���Ϣ

	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//��ӡ����
	DisplayBoard(show, ROW, COL);

	//������
	SetMine(mine, ROW, COL, EASY_COUNT);

	//�Ų���
	FindMine(mine, show, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��->\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ->\n");
			game();//��ʼ��Ϸ
			break;
		case 0:
			printf("�˳���Ϸ->\n");
			break;
		default:
			printf("ѡ�����������ѡ��->\n");
		}
	} while (input);
	return 0;
}
