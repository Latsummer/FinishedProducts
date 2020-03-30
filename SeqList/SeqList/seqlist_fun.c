#include"seqlist.h"

void Realoc(SeqList* ps)//����
{
	ps->capacity += 20;
	ps = realloc(ps, ps->capacity * sizeof(SLDateType));
}

void SeqListInit(SeqList* ps)//��ʼ��
{
	ps->capacity = 20;
	ps->a = (SLDateType*)malloc(sizeof(SLDateType)* ps->capacity);
	ps->size = 0;
}

void SeqListPushFront(SeqList* ps, SLDateType x)//ͷ��
{
	if (ps->size >= ps->capacity)
	{
		Realoc(ps);//����
	}
	size_t end = ps->size;
	while (end > 0)
	{
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPushBack(SeqList* ps, SLDateType x)//β��
{
	if (ps->size >= ps->capacity)
	{
		Realoc(ps);//����
	}
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)//posλ�ò���
{
	if (ps->size >= ps->capacity)
	{
		Realoc(ps);//����
	}
	size_t end = ps->size;
	while (end > (pos - 1))
	{
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[pos - 1] = x;
	ps->size++;
}

void SeqListPopFront(SeqList* ps)//ͷɾ
{
	for (size_t i = 0; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListPopBack(SeqList* ps)//βɾ
{
	ps->size--;
}

void SeqListErase(SeqList* ps, size_t pos)//posλ��ɾ��
{
	size_t erase = pos - 1;
	while (erase < ps->size)
	{
		ps->a[erase] = ps->a[erase + 1];
		erase++;
	}
	ps->size--;
}

int SeqListFind(SeqList* ps, SLDateType x)//����
{
	size_t find = 0;
	while (find < ps->size)
	{
		if (ps->a[find] == x)
		{
			return find + 1;
		}
		find++;
	}

	return 0;
}

void SeqListPrint(SeqList* ps)//��ӡ
{
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListDestory(SeqList* ps)//���
{
	ps->size = 0;
	printf("����գ���\n");
}