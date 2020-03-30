#define _CRT_SECURE_NO_WARNINGS 1

#include"seqlist.h"

int menu()
{
	printf("===================\n");
	printf("0.退出\n");
	printf("1.头插（x）\n");
	printf("2.尾插（x）\n");
	printf("3.任意插入（pos，x）\n");
	printf("4.头删\n");
	printf("5.尾删\n");
	printf("6.任意删（pos）\n");
	printf("7.查找（x）\n");
	printf("8.打印\n");
	printf("9.清空\n");
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
	//	SeqListPushFront,//1.头插
	//	SeqListPushBack,//2.尾插
	//	SeqListInsert,//3.任意位置插入
	//	SeqListPopFront,//4.头删
	//	SeqListPopBack,//5.尾删
	//	SeqListErase,//6.任意位置删除
	//	SeqListFind,//7.查找
	//	SeqListPrint,//8.打印
	//	SeqListDestory//9.清空
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
			SeqListPushFront(&ps, x);//1.头插
			break;
		case 2:
			scanf("%d", &x);
			SeqListPushBack(&ps, x);//2.尾插
			break;
		case 3:
			scanf("%d", &pos);
			scanf("%d", &x);
			SeqListInsert(&ps, pos, x);//3.任意位置插入
			break;
		case 4:
			SeqListPopFront(&ps);//4.头删
			break;
		case 5:
			SeqListPopBack(&ps);//5.尾删
			break;
		case 6:
			scanf("%d", &pos);
			SeqListErase(&ps, pos);//6.任意位置删除
			break;
		case 7:
			scanf("%d", &x);
			int find = SeqListFind(&ps, x);//7.查找
			if (find == 0)
			{
				printf("未找到！！！\n");
			}
			else
			{
				printf("pos == %d\n", find);
			}
			break;
		case 8:
			SeqListPrint(&ps);//8.打印
			break;
		case 9:
			SeqListDestory(&ps);//9.清空
			break;
		default:
			break;
		}
	}
	return 0;
}