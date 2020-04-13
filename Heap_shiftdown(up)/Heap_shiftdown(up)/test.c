#define _CRT_SECURE_NO_WARNINGS 1

#include"head.h"

int main()
{
	Heap hp;
	int arr[11] = { 100, 50, 30, 20, 25, 18, 10, 5, 15, 21, 23 };
	heapCreat(&hp, arr, 11);
	return 0;
}