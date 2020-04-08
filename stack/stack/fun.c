#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	ps->_capacity = 20;
	ps->_a = (STDataType*)malloc(sizeof(STDataType) * ps->_capacity);
	ps->_top = 0;
}
//����
void Realo(Stack* ps)
{
	ps->_capacity *= 2;
	ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType)* ps->_capacity);
}
// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	if (ps->_top == ps->_capacity)
	{
		Realo(ps);
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}
// ��ջ 
void StackPop(Stack* ps)
{
	int empty = StackEmpty(ps);
	if (empty)
		return;
	ps->_top--;
}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	int empty = StackEmpty(ps);
	if (empty)
		return;
	return ps->_a[ps->_top - 1];
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	return ps->_top - 1;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	if (ps->_top == 0)
		return 1;
	else
		return 0;
}
// ����ջ 
void StackDestroy(Stack* ps)
{
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
