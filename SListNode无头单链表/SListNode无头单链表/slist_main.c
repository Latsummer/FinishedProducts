#define _CRT_SECURE_NO_WARNINGS 1
#include "slist.h"

int menu()
{
	printf("===================\n");
	printf("1.��ӡ\n");
	printf("2.ͷ��\n");
	printf("3.β��\n");
	printf("4.ͷɾ\n");
	printf("5.βɾ\n");
	printf("6.posλ��\n");
	printf("7.posλɾ\n");
	printf("8.����\n");
	printf("9.Ѱ��\n");
	printf("0.�˳�\n");
	printf("===================\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

int main()
{
	SListNode* list = NULL;
	while (1)
	{
		int choice = menu();
		if (choice == 0)
			break;
		switch (choice)
		{
		case 1:
			SListPrint(list);
			break;
		case 2:
			SListPushFront(&list, 1);
			SListPushFront(&list, 2);
			SListPushFront(&list, 3);
			break;
		case 3:
			SListPushBack(&list, 2);
			break;
		case 4:
			SListPopFront(&list);
			break;
		case 5:
			SListPopBack(&list);
			break;
		case 6:
			SListInsertAfter(list->next->next,20);
			break;
		case 7:
			SListEraseAfter(list->next->next);
			break;
		case 8:
			SListDestory(list);
			list = NULL;
			break;
		case 9:

			break;
		default:
			break;
		}

	}
	return 0;
}