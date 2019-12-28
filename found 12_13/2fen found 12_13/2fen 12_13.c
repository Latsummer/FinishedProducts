#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int found = 0;
	int left = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int right = sz - 1;
	int mid = 0;
	printf("请输入要查找的数字下标:>  ");
	scanf("%d", &found);
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] > found)
			right = mid - 1;
		else if (arr[mid] < found)
			left = mid + 1;
		else
		{
			printf("找到了，数字 %d 的下标是 %d \n",found,mid);
			break;
		}
	}
	if (left > right)
		printf("没找到\n");
	return 0;
}