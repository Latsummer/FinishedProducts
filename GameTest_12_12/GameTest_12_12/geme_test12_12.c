#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("#####猜数字游戏#####\n");
	printf("####################\n");
	printf("######1. PLAY ######\n");
	printf("######2. EXIT ######\n");
	printf("####################\n");

}
void game()
{
	int guss = 0;
	int guss_man = 0;
	int i = 0;
	guss = rand() % 100;
	printf("猜一个0至100的数字吧:>  ");
	do
	{
		scanf("%d", &guss_man);
		if (guss_man > guss)
		{
			printf("\n猜大了。。\n\n");
			i++;
			printf("这是你第 %d 次猜了奥！！\n\n",i);
		}
		else if (guss_man < guss)
		{
			printf("\n猜小了。。\n\n");
			i++;
			printf("这是你第 %d 次猜了奥！！\n\n", i);
		}
		else
		{
			printf("猜对惹！！！\n\n\n");
			printf("你个憨憨一共猜了 %d 次才TM猜对\n\n\n",i);
			break;
		}

	} while (1);
}
int main()
{
	srand((unsigned int)time(0));
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			game();
		    break;
		}
		case 2:
			goto out;
		default:
			printf("请输入正确的数字....\n");
		}
	} while (1);
	out:	return 0;
}