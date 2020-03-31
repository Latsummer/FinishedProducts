#define _CRT_SECURE_NO_WARNINGS 1
#include"slist.h"

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* new = (SListNode*)malloc(sizeof(SListNode));
	new->data = x;
	new->next = NULL;
	return new;
}
// 单链表打印
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* new = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = new;
		return;
	}
	SListNode* cur = *pplist;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = new;
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* new = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = new;
		return;
	}
	new->next = *pplist;
	*pplist = new;
}
// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	SListNode* back = *pplist;
	SListNode* before = NULL;
	if (back == NULL || back->next == NULL)
	{
		free(back);
		*pplist = NULL;
		return;
	}

	while (back->next)
	{
		before = back;
		back = back->next;
	}
	free(back);
	back = NULL;
	before->next = NULL;

}
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	SListNode* first = *pplist;
	if (first == NULL || first->next == NULL)
	{
		free(first);
		*pplist = NULL;
		return;
	}
	SListNode* after = first->next;
	free(first);
	*pplist = after;

}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* find = plist;
	while (find)
	{
		if (find->data == x)
			return find;
		find = find->next;
	}
	return NULL;
}
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	if (pos == NULL)
	{
		printf("不存在！\n");
		return;
	}
	SListNode* new = BuySListNode(x);
	SListNode* next = pos->next;
	pos->next = new;
	new->next = next;
}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	if (pos == NULL)
	{
		printf("不存在！\n");
		return;
	}
	SListNode* del = pos->next;
	SListNode* del_next = del->next;
	free(del);
	pos->next = del_next;
}
// 单链表的销毁
void SListDestory(SListNode* plist)
{
	if (plist == NULL)
		return;
	else
	{
		SListNode* destory;
		while (plist)
		{
			destory = plist->next;
			free(plist);
			plist = destory;
		}
		plist = NULL;
	}
	
}