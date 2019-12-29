#define _CRT_SECURE_NO_WARNINGS 1

#include"扫雷12_29.h"

void game()
{
	printf("开始游戏\n");
	char mine[ROWS][COLS] = { 0 };//存放雷‘0’
	char show[ROWS][COLS] = { 0 };//存放排雷信息‘*’
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');//初始化
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
		printf("请选择：>   ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		    game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请正确输入！！！\n\n");
		}
	} while (input);
}

int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}