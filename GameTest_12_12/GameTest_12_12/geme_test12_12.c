#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("#####��������Ϸ#####\n");
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
	printf("��һ��0��100�����ְ�:>  ");
	do
	{
		scanf("%d", &guss_man);
		if (guss_man > guss)
		{
			printf("\n�´��ˡ���\n\n");
			i++;
			printf("������� %d �β��˰£���\n\n",i);
		}
		else if (guss_man < guss)
		{
			printf("\n��С�ˡ���\n\n");
			i++;
			printf("������� %d �β��˰£���\n\n", i);
		}
		else
		{
			printf("�¶��ǣ�����\n\n\n");
			printf("�������һ������ %d �β�TM�¶�\n\n\n",i);
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
			printf("��������ȷ������....\n");
		}
	} while (1);
	out:	return 0;
}