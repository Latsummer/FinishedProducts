#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"


// ��ʼ������ 
void QueueInit(Queue* q)
{
	q->_front = NULL;
	q->_rear = NULL;
	q->size = 0;
}

//�����ڵ�
QNode* CreatNode(QDataType data)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->_data = data;
	newNode->_next = NULL;
	return newNode;
}

// ��β����� 
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
// ��ͷ������ 
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
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	return q->_front->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	return q->_rear->_data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	return q->size;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	if (q->_front == NULL)
		return 1;
	else
		return 0;
}
// ���ٶ��� 
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
