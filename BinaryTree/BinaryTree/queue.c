#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"


// 初始化队列 
void QueueInit(Queue* q)
{
	q->_front = NULL;
	q->_rear = NULL;
	q->size = 0;
}

//创建节点
QNode* CreatNode(QDataType data)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->_data = data;
	newNode->_next = NULL;
	return newNode;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	QNode* newNode = CreatNode(data);
	if (q->_rear == NULL)
	{
		q->_front = newNode;
		q->_rear = newNode;
	}
	else
	{
		q->_rear->_next = newNode;
		q->_rear = newNode;
	}
	q->size++;
}
// 队头出队列 
void QueuePop(Queue* q)
{
	if (q->_front)
	{
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		if (q->_front == NULL)
			q->_rear = NULL;
		q->size--;
	}
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	return q->_front->_data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	return q->_rear->_data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	return q->size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	if (q->_front == NULL)
		return 1;
	else
		return 0;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	QNode* cur = q->_front;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = NULL;
	q->_rear = NULL;
	q->size = 0;
}
