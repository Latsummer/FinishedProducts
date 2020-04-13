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

	//建堆，从最后一个非叶子节点开始 （size - 2）/ 2
	for (int parent = (size - 2) / 2; parent >= 0; parent--)
	{
		shiftDown(hp->_arr, size, parent);
	}
}

//小堆向下调整
void shiftDown(HPDataType* arr, int size, int parent)
{
	//左孩子位置
	int child = 2 * parent + 1;
	while (child < size)//当孩子不越界
	{
		//在左右孩子中选一个最小的
		if (child + 1 < size && arr[child + 1] < arr[child])
			child++;
		//和父节点进行比较，如果最小的孩子仍小于父节点，说明这个孩子在三个节点中是最小的，交换其和父节点的位置
		if (arr[child] < arr[parent])
		{
			Swap(arr, child, parent);
			//更新孩子位置
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

