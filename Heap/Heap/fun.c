#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

void Swap(HPDataType* a, int left, int right)
{
	int tmp = a[left];
	a[left] = a[right];
	a[right] = tmp;
}

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int size)
{
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)* size);
	memcpy(hp->_a, a, sizeof(HPDataType)* size);
	hp->_size = size;
	hp->_capacity = size;

	for (int parent = (size - 2) / 2; parent >= 0; parent--)
	{
		shiftDown(hp->_a, size, parent);
	}
}
void shiftDown(HPDataType* a, int size, int parent)
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
		if (child + 1 < size && a[child + 1] > a[child])
			child++;
		if (a[child] > a[parent])
		{
			Swap(a, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void shiftUp(HPDataType* a, int child)
{
	//小堆
	/*int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(a, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}*/
	//大堆
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(a, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_capacity = 0;
	hp->_size = 0;
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->_size >= hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)* hp->_capacity);
	}
	hp->_a[hp->_size++] = x;
	shiftUp(hp->_a, hp->_size - 1);

}
// 堆的删除
void HeapPop(Heap* hp)
{
	if (hp->_size > 0)
	{
		Swap(hp->_a, 0, hp->_size - 1);
		hp->_size--;
		shiftDown(hp->_a, hp->_size, 0);
	}
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	if (hp->_size == 0)
		return 1;
	return 0;
}

// 对数组进行堆排序
void HeapSort(int* a, int size)
{
	for (int parent = (size - 2) / 2; parent >= 0; parent--)
	{
		shiftDown(a, size, parent);
	}
	while (size > 1)
	{
		Swap(a, 0, size - 1);
		size--;
		shiftDown(a, size, 0);
	}
}

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k)
{
	//建立大堆找最小值
	Heap hp;
	HeapCreate(&hp, a, k);
	for (int i = k; i < n; i++)
	{
		if (a[i] < HeapTop(&hp))
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d\n", HeapTop(&hp));
		HeapPop(&hp);
	}
	////减小堆找最大值
	//Heap hp;
	//HeapCreate(&hp, a, k);
	//for (int i = k; i < n; i++)
	//{
	//	if (a[i] > HeapTop(&hp))
	//	{
	//		HeapPop(&hp);
	//		HeapPush(&hp, a[i]);
	//	}
	//}
	//for (int i = 0; i < k; i++)
	//{
	//	printf("%d\n", HeapTop(&hp));
	//	HeapPop(&hp);
	//}
}
void TestTopk();