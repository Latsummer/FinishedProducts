#define _CRT_SECURE_NO_WARNINGS 1
#include "qnode.h"


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
	/*QNode* next;
	int empty = QueueEmpty(q);
	if (empty)
		return;
	next = q->_front->_next;
	free(q->_front);
	q->_front = next;*/
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
	int empty = QueueEmpty(q);
	if (!empty)
		return q->_front->_data;
	return -1;

}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	int empty = QueueEmpty(q);
	if (!empty)
		return q->_rear->_data;
	return -1;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	/*QNode* cur = q->_front;
	int nums = 0;
	while (cur)
	{
		nums++;
		cur = cur->_next;
	}
	return nums;*/
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
	/*int empty = QueueEmpty(q);
	if (empty)
		return;
	while (q->_front)
		QueuePop(q);*/
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
