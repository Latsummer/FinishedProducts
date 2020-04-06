#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"


void test1(ListNode* pHead)
{
	ListPushBack(pHead, 1);
	ListPushBack(pHead, 2);
	ListPushBack(pHead, 3);
	ListPushBack(pHead, 4);
	ListPushBack(pHead, 5);

	/*ListPushFront(pHead, 9);
	ListPushFront(pHead, 99);
	ListPushFront(pHead, 999);

	ListPopFront(pHead);*/

	ListInsert(pHead->_next->_next->_next, 666);
	ListErase(pHead->_next->_next->_next->_next);

	ListPopBack(pHead);
	ListPrint(pHead);
	ListNode* fin = ListFind(pHead, 4);
	if (fin != NULL)
		printf("found! %d\n", fin->_data);
	ListDestory(pHead);
}

int main()
{
	ListNode pHead;
	Init(&pHead);
	test1(&pHead);
	return 0;
}