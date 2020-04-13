#define _CRT_SECURE_NO_WARNINGS 1
#include "head.h"

void Swap(HPDataType* arr, int left, int right)
{
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}

void heapCreat(Heap* hp, HPDataType* arr, int size)
{
	hp->_arr = (HPDataType*)malloc(sizeof(HPDataType)* size);
	memcpy(hp->_arr, arr, sizeof(HPDataType)* size);
	hp->_size = size;
	hp->_capacity = size;

	//���ѣ������һ����Ҷ�ӽڵ㿪ʼ ��size - 2��/ 2
	for (int parent = (size - 2) / 2; parent >= 0; parent--)
	{
		shiftDown(hp->_arr, size, parent);
	}
}

//С�����µ���
void shiftDown(HPDataType* arr, int size, int parent)
{
	//����λ��
	int child = 2 * parent + 1;
	while (child < size)//�����Ӳ�Խ��
	{
		//�����Һ�����ѡһ����С��
		if (child + 1 < size && arr[child + 1] < arr[child])
			child++;
		//�͸��ڵ���бȽϣ������С�ĺ�����С�ڸ��ڵ㣬˵����������������ڵ�������С�ģ�������͸��ڵ��λ��
		if (arr[child] < arr[parent])
		{
			Swap(arr, child, parent);
			//���º���λ��
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void shiftUp(HPDataType* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[child] < arr[parent])
		{
			Swap(arr, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

