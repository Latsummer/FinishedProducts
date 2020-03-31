#define _CRT_SECURE_NO_WARNINGS 1
#include"slist.h"

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* new = (SListNode*)malloc(sizeof(SListNode));
	new->data = x;
	new->next = NULL;
	return new;
}
// �������ӡ
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
// ������β��
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
// �������ͷ��
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
// �������βɾ
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
// ������ͷɾ
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
// ���������
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
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	if (pos == NULL)
	{
		printf("�����ڣ�\n");
		return;
	}
	SListNode* new = BuySListNode(x);
	SListNode* next = pos->next;
	pos->next = new;
	new->next = next;
}
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos)
{
	if (pos == NULL)
	{
		printf("�����ڣ�\n");
		return;
	}
	SListNode* del = pos->next;
	SListNode* del_next = del->next;
	free(del);
	pos->next = del_next;
}
// �����������
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