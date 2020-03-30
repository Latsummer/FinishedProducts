#define _CRT_SECURE_NO_WARNINGS 1

#include"seqlist.h"

int menu()
{
	printf("===================\n");
	printf("0.�˳�\n");
	printf("1.ͷ�壨x��\n");
	printf("2.β�壨x��\n");
	printf("3.������루pos��x��\n");
	printf("4.ͷɾ\n");
	printf("5.βɾ\n");
	printf("6.����ɾ��pos��\n");
	printf("7.���ң�x��\n");
	printf("8.��ӡ\n");
	printf("9.���\n");
	printf("===================\n\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

int main()
{
	size_t pos = 0;
	SLDateType x = 0;
	SeqList ps;
	SeqListInit(&ps);
	//typedef void(*Func)(SeqList*);
	//Func function[] =
	//{
	//	NULL,
	//	SeqListPushFront,//1.ͷ��
	//	SeqListPushBack,//2.β��
	//	SeqListInsert,//3.����λ�ò���
	//	SeqListPopFront,//4.ͷɾ
	//	SeqListPopBack,//5.βɾ
	//	SeqListErase,//6.����λ��ɾ��
	//	SeqListFind,//7.����
	//	SeqListPrint,//8.��ӡ
	//	SeqListDestory//9.���
	//};
	while (1)
	{
		int choice = menu();
		if (choice == 0)
		{
			break;
		}
		switch (choice)
		{
		case 1:
			scanf("%d", &x);
			SeqListPushFront(&ps, x);//1.ͷ��
			break;
		case 2:
			scanf("%d", &x);
			SeqListPushBack(&ps, x);//2.β��
			break;
		case 3:
			scanf("%d", &pos);
			scanf("%d", &x);
			SeqListInsert(&ps, pos, x);//3.����λ�ò���
			break;
		case 4:
			SeqListPopFront(&ps);//4.ͷɾ
			break;
		case 5:
			SeqListPopBack(&ps);//5.βɾ
			break;
		case 6:
			scanf("%d", &pos);
			SeqListErase(&ps, pos);//6.����λ��ɾ��
			break;
		case 7:
			scanf("%d", &x);
			int find = SeqListFind(&ps, x);//7.����
			if (find == 0)
			{
				printf("δ�ҵ�������\n");
			}
			else
			{
				printf("pos == %d\n", find);
			}
			break;
		case 8:
			SeqListPrint(&ps);//8.��ӡ
			break;
		case 9:
			SeqListDestory(&ps);//9.���
			break;
		default:
			break;
		}
	}
	return 0;
}