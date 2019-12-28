#define _CRT_SECURE_NO_WARNINGS 1

#include "game12_21.h"
void game()
{
	char board[ROW][COL] = {0};
	char ret = 0;
	InitBoard(board, ROW, COL);
	PrintBoard(board, ROW, COL);
	while (1)
	{
		Player(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		Computer(board , ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("���Ӯ��\n");
	else if (ret == '#')
		printf("����Ӯ��\n");
	else if (ret == 'Q')
		printf("ƽ�֣�\n");
	
}
void menu()
{
	int input = 0;
	do
	{
		printf("*******************\n");
		printf("****** 1.PLAY *****\n");
		printf("****** 0.EXIT *****\n");
		printf("*******************\n");
		scanf("%d", &input);
		if (input == 1)
			game();
		else if (input == 0)
		{
			printf("�˳���Ϸ\n");
			break;
		}
			
		else
			printf("�Ƿ�����\n");

	} while (1);
}
int main()
{
	srand((unsigned int)time(NULL));
	menu();
	return 0;
}