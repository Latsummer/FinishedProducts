#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

typedef void(*FUNC) (int*, int);
FUNC sort[] =
{
	printarr,//0
	insert_Sort,//1
	shell_Sort,//2
	select_Sort,//3
	select2_Sort,//4
	heap_Sort,//5
	bubble_Sort,//6
	quick_Sort_NoR_Stack,//7
	quick_Sort_NoR_Queue,//8
	merge_Sort,//9
	count_Sort,//10
};

void sort_test(int* bigarr, int size)
{
	sort[0](bigarr, size);
	sort[10](bigarr, size);
	//quick_Sort(bigarr, 0, size - 1);
	sort[0](bigarr, size);
}

void time_test(int* bigarr, int n)
{
	int* copy = (int*)malloc(sizeof(int)* n);
	memcpy(copy, bigarr, 4 * n);
	
	size_t begin = clock();
	sort[9](bigarr, n);
	size_t end = clock();

	printf("%d ms\n", end - begin);

	begin = clock();
	//sort[5](copy, n);
	quick_Sort(copy, 0, n - 1);
	end = clock();
	printf("%d ms\n", end - begin);

}

int main()
{
	srand((unsigned int)time(NULL));
	int n = 0;
	scanf("%d", &n);
	int* bigarr = (int*)malloc(sizeof(int)* n);
	for (int i = 0; i < n; i++)
		bigarr[i] = rand();
	
	//sort_test(bigarr, n);
	time_test(bigarr, n);

	return 0;
}