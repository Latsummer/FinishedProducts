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
	printf("������Ҫ���ҵ������±�:>  ");
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
			printf("�ҵ��ˣ����� %d ���±��� %d \n",found,mid);
			break;
		}
	}
	if (left > right)
		printf("û�ҵ�\n");
	return 0;
}