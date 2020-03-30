#include"seqlist.h"

void Realoc(SeqList* ps)//¿©»›
{
	ps->capacity += 20;
	ps = realloc(ps, ps->capacity * sizeof(SLDateType));
}

void SeqListInit(SeqList* ps)//≥ı ºªØ
{
	ps->capacity = 20;
	ps->a = (SLDateType*)malloc(sizeof(SLDateType)* ps->capacity);
	ps->size = 0;
}

void SeqListPushFront(SeqList* ps, SLDateType x)//Õ∑≤Â
{
	if (ps->size >= ps->capacity)
	{
		Realoc(ps);//¿©»›
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

void SeqListPushBack(SeqList* ps, SLDateType x)//Œ≤≤Â
{
	if (ps->size >= ps->capacity)
	{
		Realoc(ps);//¿©»›
	}
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)//posŒª÷√≤Â»Î
{
	if (ps->size >= ps->capacity)
	{
		Realoc(ps);//¿©»›
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

void SeqListPopFront(SeqList* ps)//Õ∑…æ
{
	for (size_t i = 0; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListPopBack(SeqList* ps)//Œ≤…æ
{
	ps->size--;
}

void SeqListErase(SeqList* ps, size_t pos)//posŒª÷√…æ≥˝
{
	size_t erase = pos - 1;
	while (erase < ps->size)
	{
		ps->a[erase] = ps->a[erase + 1];
		erase++;
	}
	ps->size--;
}

int SeqListFind(SeqList* ps, SLDateType x)//≤È’“
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

void SeqListPrint(SeqList* ps)//¥Ú”°
{
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListDestory(SeqList* ps)//«Âø’
{
	ps->size = 0;
	printf("“—«Âø’£°£°\n");
}