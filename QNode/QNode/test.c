#define _CRT_SECURE_NO_WARNINGS 1
#include"qnode.h"

void test1(Queue* q)
{
	QueuePush(q, 1);
	QueuePush(q, 2);
	QueuePush(q, 3);
	QueuePush(q, 4);
	QueuePush(q, 5);

	QueuePop(q);
	QueuePop(q);
	QueuePop(q);
	QueuePop(q);
	QueuePop(q);
	QueuePop(q);

	QueueBack(q);
	QueueFront(q);

}

int main()
{
	Queue q;
	QueueInit(&q);
	test1(&q);
	return 0;
}