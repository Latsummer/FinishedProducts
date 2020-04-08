#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"

// 初始化栈 
void StackInit(Stack* ps)
{
	ps->_capacity = 20;
	ps->_a = (STDataType*)malloc(sizeof(STDataType) * ps->_capacity);
	ps->_top = 0;
}
//扩容
void Realo(Stack* ps)
{
	ps->_capacity *= 2;
	ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType)* ps->_capacity);
}
// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	if (ps->_top == ps->_capacity)
	{
		Realo(ps);
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}
// 出栈 
void StackPop(Stack* ps)
{
	int empty = StackEmpty(ps);
	if (empty)
		return;
	ps->_top--;
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	int empty = StackEmpty(ps);
	if (empty)
		return;
	return ps->_a[ps->_top - 1];
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	return ps->_top - 1;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	if (ps->_top == 0)
		return 1;
	else
		return 0;
}
// 销毁栈 
void StackDestroy(Stack* ps)
{
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
