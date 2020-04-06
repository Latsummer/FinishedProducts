#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"

void Init(ListNode* pHead)
{
	pHead->_data = 0;
	pHead->_next = pHead;
	pHead->_prev = pHead;
}

ListNode* ListCreate(LTDataType x)
{
	ListNode* Newnode = (ListNode*)malloc(sizeof(ListNode));
	Newnode->_data = x;
	Newnode->_prev = NULL;
	Newnode->_next = NULL;

	return Newnode;
}
void ListDestory(ListNode* pHead) //Ïú»Ù
{
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pHead = NULL;
}
void ListPrint(ListNode* pHead)//´òÓ¡
{
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
void ListPushBack(ListNode* pHead, LTDataType x)//Î²²å
{
	ListNode* Newnode = ListCreate(x);
	ListNode* last = pHead->_prev;

	last->_next = Newnode;
	Newnode->_prev = last;

	Newnode->_next = pHead;
	pHead->_prev = Newnode;

}
void ListPopBack(ListNode* pHead)//Î²É¾
{
	ListNode* last = pHead->_prev;
	pHead->_prev = last->_prev;
	last->_prev->_next = pHead;

	free(last);
}
void ListPushFront(ListNode* pHead, LTDataType x)
{
	ListNode* Newnode = ListCreate(x);
	ListNode* Front = pHead->_next;

	Newnode->_next = Front;
	Front->_prev = Newnode;

	pHead->_next = Newnode;
	Newnode->_prev = pHead;
}
void ListPopFront(ListNode* pHead)
{
	ListNode* Front = pHead->_next;
	pHead->_next = Front->_next;
	Front->_next->_prev = pHead;

	free(Front);
}
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_data == x)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* Newnode = ListCreate(x);
	ListNode* before = pos->_prev;

	Newnode->_prev = before;
	Newnode->_next = pos;

	before->_next = Newnode;
	pos->_prev = Newnode;
}
void ListErase(ListNode* pos)
{
	ListNode* before = pos->_prev;
	ListNode* after = pos->_next;

	before->_next = after;
	after->_prev = before;

	free(pos);
}