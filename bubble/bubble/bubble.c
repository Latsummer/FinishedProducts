#define _CRT_SECURE_NO_WARNINGS 1

#define SIZE 200

#include<stdio.h>
#include<stdlib.h>

void InitA(int* a, int size)
{
	int i = size;
	int j = 0;
	while (i > 0)
	{
		a[j] = i;
		i--;
		j++;
	}
}

void Bubble(int* a, int size)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size -1 - i; j++)
		{
			if (a[j]>a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

void Print(int* a, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
		printf("%d\n",a[i]);
}

int main()
{
	int a[SIZE] = { 0 };
	InitA(a, SIZE);
	Bubble(a,SIZE);
	Print(a, SIZE);
	system("pause");
	return 0;
}