#define _CRT_SECURE_NO_WARNINGS 1

#include"ɨ��12_29.h"

void game()
{
	printf("��ʼ��Ϸ\n");
	char mine[ROWS][COLS] = { 0 };//����ס�0��
	char show[ROWS][COLS] = { 0 };//���������Ϣ��*��
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');//��ʼ��
	/*DisplayBoard(mine, ROW, COL);
	printf("\n");
	DisplayBoard(show, ROW, COL);*/
	SetMine(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	FindMine(mine, show, ROW, COL);



}
void menu()
{
	printf("##################\n");
	printf("#### 1. PLAY #####\n");
	printf("#### 0. EXIT #####\n");
	printf("##################\n");
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>   ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		    game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����ȷ���룡����\n\n");
		}
	} while (input);
}

int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}