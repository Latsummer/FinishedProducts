#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

void test1(Stack* ps)
{
	StackPush(ps, 1);
	StackPush(ps, 2);
	StackPush(ps, 3);
	StackPush(ps, 4);
	StackPush(ps, 5);

	StackPop(ps);
	StackPop(ps);
	StackPop(ps);
	StackPop(ps);
	StackPop(ps);
	StackPop(ps);
	StackPop(ps);

	StackPush(ps, 5);
	StackPush(ps, 4);
	StackPush(ps, 3);
	StackPush(ps, 2);
	StackPush(ps, 1);
	printf("%d\n", StackSize(ps));


}

int main()
{
	Stack ps;
	StackInit(&ps);
	test1(&ps);
	return 0;
}