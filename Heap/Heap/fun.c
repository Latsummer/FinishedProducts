#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

void Swap(HPDataType* a, int left, int right)
{
	int tmp = a[left];
	a[left] = a[right];
	a[right] = tmp;
}

// �ѵĹ���
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
	//С��
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
	//���
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
// �ѵ�����
void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_capacity = 0;
	hp->_size = 0;
}
// �ѵĲ���
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
// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	if (hp->_size > 0)
	{
		Swap(hp->_a, 0, hp->_size - 1);
		hp->_size--;
		shiftDown(hp->_a, hp->_size, 0);
	}
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	return hp->_size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	if (hp->_size == 0)
		return 1;
	return 0;
}

// ��������ж�����
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

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k)
{
	//�����������Сֵ
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
	////��С�������ֵ
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