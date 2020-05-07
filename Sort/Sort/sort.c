#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"Stack.h"
#include"Queue.h"

void swap(int* arr, int left, int right)
{
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}

void printarr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void insert_Sort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int end = i;
		int key = arr[end + 1];
		while (end >= 0 && arr[end] > key)
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = key;
	}
}

void shell_Sort(int* arr, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < size - gap; i++)
		{
			int end = i;
			int key = arr[end + gap];
			while (end >= 0 && arr[end] > key)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = key;
		}
	}
}

void select_Sort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int start = i;
		int min = start;
		for (int j = start + 1; j < size; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		swap(arr, start, min);
	}
}

void select2_Sort(int* arr, int size)
{
	int begin = 0;
	int end = size - 1;
	while (end > begin)
	{
		int min = begin;
		int max = end;
		for (int i = begin + 1; i <= end; i++)
		{
			if (arr[i] >= arr[max])
				max = i;
			if (arr[i] < arr[min])
				min = i;
		}
		swap(arr, begin, min);
		if (max == begin)
			max = min;
		swap(arr, end, max);

		begin++;
		end--;
	}
}

void shiftDown(int* arr, int size, int parent)
{
	//小堆
	//int child = 2 * parent + 1;
	//while (child < size)
	//{
	//	if (child + 1 < size && a[child + 1] < a[child])
	//		child++;
	//	if (a[child] < a[parent])
	//	{
	//		Swap(a, child, parent);
	//		parent = child;
	//		child = 2 * parent + 1;
	//	}
	//	else
	//	{
	//		break;
	//	}
	//}
	//大堆
	int child = 2 * parent + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child + 1] > arr[child])
			child++;
		if (arr[child] > arr[parent])
		{
			swap(arr, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void heap_Sort(int* arr, int size)
{
	for (int parent = (size - 2) / 2; parent >= 0; parent--)
	{
		shiftDown(arr, size, parent);
	}
	while (size > 1)
	{
		swap(arr, 0, size - 1);
		size--;//循环删除堆顶元素并向下调整
		shiftDown(arr, size, 0);
	}
}

void bubble_Sort(int* arr, int size)
{
	while (size)
	{
		int flag = 1;
		int end = size;
		for (int i = 1; i < end; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				swap(arr, i - 1, i);
				flag = 0;
			}
		}
		if (flag)
			break;
		size--;
	}
}

int getMid(int* arr, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	if (arr[begin] < arr[end])
	{
		if (arr[mid] < arr[end])
			return mid;
		else
			return arr[begin] > arr[end] ? begin : end;
	}
	else
	{
		if (arr[end] < arr[mid])
			return mid;
		else
			return arr[begin] < arr[end] ? begin : end;
	}
}

int partion(int* arr, int begin, int end)//hora划分
{
	//int key = arr[begin];//基准值
	int mid = getMid(arr, begin, end);
	swap(arr, mid, begin);

	int key = arr[begin];//基准值
	int start = begin;
	while (begin < end)
	{
		while (end > begin && arr[end] >= key)
			end--;//从后往前找到第一个小于key的值
		while (end > begin && arr[begin] <= key)
			begin++;//从前向后找到第一个大于key的值
		swap(arr, begin, end);//交换二者
	}
	swap(arr, start, begin);//交换基准值和相遇位置
	return begin;//返回改变后的基准值的索引
}

int partion2(int* arr, int begin, int end)//挖坑法
{
	int mid = getMid(arr, begin, end);
	swap(arr, mid, begin);

	int key = arr[begin];//挖掉基准值
	while (end > begin)
	{
		while (end > begin && arr[end] >= key)
			end--;//先从后往前找到第一个小于key的值
		arr[begin] = arr[end];//填补基准值挖出来的坑
		while (end > begin && arr[begin] <= key)
			begin++;//从前往后找到第一个大于key的值
		arr[end] = arr[begin];//填补上一步挖的坑
	}
	arr[begin] = key;//相遇时把基准值塞进来
	return begin;
}

int partion3(int* arr, int begin, int end)//前后指针法
{
	int mid = getMid(arr, begin, end);
	swap(arr, mid, begin);

	int prev = begin;//prev：最后一个小于基准值的位置
	int cur = prev + 1;//cur：新发现的下一个小于基准值的位置
	int key = arr[begin];//基准值
	while (cur <= end)
	{
		if (arr[cur] < key && ++prev != cur)//新发现的小于基准值的数据和prev不连续，说明中间含有大于基准值的数据，故交换
			swap(arr, cur, prev);//小数据向前，大数据向后
		cur++;
	}
	swap(arr, begin, prev);
	return prev;
}

void quick_Sort(int* arr, int begin, int end)//快速排序
{
	if (begin >= end)
		return;
	int keyPos = partion2(arr, begin, end);
	quick_Sort(arr, begin, keyPos - 1);
	quick_Sort(arr, keyPos + 1, end);
}

//栈实现非递归
void quick_Sort_NoR_Stack(int* arr, int size)
{
	Stack st;
	StackInit(&st);
	if (size > 1)
	{
		StackPush(&st, size - 1);
		StackPush(&st, 0);
	}
	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		int keyPos = partion2(arr, begin, end);
		 
		if (keyPos + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, keyPos + 1);
		}
		if (begin < keyPos - 1)
		{
			StackPush(&st, keyPos - 1);
			StackPush(&st, begin);
		}
	}
}

//队列实现非递归
void quick_Sort_NoR_Queue(int* arr, int size)
{
	Queue q;
	QueueInit(&q);
	if (size > 1)
	{
		QueuePush(&q, 0);
		QueuePush(&q, size - 1);
	}
	while (!QueueEmpty(&q))
	{
		int begin = QueueFront(&q);
		QueuePop(&q);
		int end = QueueFront(&q);
		QueuePop(&q);

		int keyPos = partion2(arr, begin, end);

		if (begin < keyPos - 1)
		{
			QueuePush(&q, begin);
			QueuePush(&q, keyPos - 1);
		}
		if (end > keyPos + 1)
		{
			QueuePush(&q, keyPos + 1);
			QueuePush(&q, end);
		}
	}
}

void merge(int* arr, int begin, int mid, int end, int* tmp)
{
	int begin1 = begin, end1 = mid, begin2 = mid + 1, end2 = end;
	int idx = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])
			tmp[idx++] = arr[begin1++];
		else
			tmp[idx++] = arr[begin2++];
	}
	if (begin1 <= end1)
		memcpy(tmp + idx, arr + begin1, sizeof(int)* (end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, arr + begin2, sizeof(int)*(end2 - begin2 + 1));
	memcpy(arr + begin, tmp + begin, sizeof(int)* (end - begin + 1));
}

void merge_SortR(int* arr, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;

	merge_SortR(arr, begin, mid, tmp);
	merge_SortR(arr, mid + 1, end, tmp);

	merge(arr, begin, mid, end, tmp);
}

void merge_Sort(int* arr, int size)
{
	int* tmp = (int*)malloc(sizeof(int)* size);

	merge_SortR(arr, 0, size - 1, tmp);
	free(tmp);
}