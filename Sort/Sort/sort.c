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
	//С��
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
	//���
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
		size--;//ѭ��ɾ���Ѷ�Ԫ�ز����µ���
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

int partion(int* arr, int begin, int end)//hora����
{
	//int key = arr[begin];//��׼ֵ
	int mid = getMid(arr, begin, end);
	swap(arr, mid, begin);

	int key = arr[begin];//��׼ֵ
	int start = begin;
	while (begin < end)
	{
		while (end > begin && arr[end] >= key)
			end--;//�Ӻ���ǰ�ҵ���һ��С��key��ֵ
		while (end > begin && arr[begin] <= key)
			begin++;//��ǰ����ҵ���һ������key��ֵ
		swap(arr, begin, end);//��������
	}
	swap(arr, start, begin);//������׼ֵ������λ��
	return begin;//���ظı��Ļ�׼ֵ������
}

int partion2(int* arr, int begin, int end)//�ڿӷ�
{
	int mid = getMid(arr, begin, end);
	swap(arr, mid, begin);

	int key = arr[begin];//�ڵ���׼ֵ
	while (end > begin)
	{
		while (end > begin && arr[end] >= key)
			end--;//�ȴӺ���ǰ�ҵ���һ��С��key��ֵ
		arr[begin] = arr[end];//���׼ֵ�ڳ����Ŀ�
		while (end > begin && arr[begin] <= key)
			begin++;//��ǰ�����ҵ���һ������key��ֵ
		arr[end] = arr[begin];//���һ���ڵĿ�
	}
	arr[begin] = key;//����ʱ�ѻ�׼ֵ������
	return begin;
}

int partion3(int* arr, int begin, int end)//ǰ��ָ�뷨
{
	int mid = getMid(arr, begin, end);
	swap(arr, mid, begin);

	int prev = begin;//prev�����һ��С�ڻ�׼ֵ��λ��
	int cur = prev + 1;//cur���·��ֵ���һ��С�ڻ�׼ֵ��λ��
	int key = arr[begin];//��׼ֵ
	while (cur <= end)
	{
		if (arr[cur] < key && ++prev != cur)//�·��ֵ�С�ڻ�׼ֵ�����ݺ�prev��������˵���м京�д��ڻ�׼ֵ�����ݣ��ʽ���
			swap(arr, cur, prev);//С������ǰ�����������
		cur++;
	}
	swap(arr, begin, prev);
	return prev;
}

void quick_Sort(int* arr, int begin, int end)//��������
{
	if (begin >= end)
		return;
	int keyPos = partion2(arr, begin, end);
	quick_Sort(arr, begin, keyPos - 1);
	quick_Sort(arr, keyPos + 1, end);
}

//ջʵ�ַǵݹ�
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

//����ʵ�ַǵݹ�
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