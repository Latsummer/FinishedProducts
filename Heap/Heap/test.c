#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

void test1(Heap* hp)
{
	int arr[11] = { 100, 50, 30, 20, 25, 18, 10, 5, 15, 21, 23 };
	HeapCreate(hp, arr, 11);
	HeapPrint(hp);
	HeapPush(hp, 1);
	HeapPrint(hp);
	HeapPop(hp);
	HeapPush(hp, 0);
	HeapPrint(hp);

}

int main()
{
	/*Heap hp;
	test1(&hp);*/
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	/*HeapSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}*/
	PrintTopK(a, 10, 5);
	return 0;
}