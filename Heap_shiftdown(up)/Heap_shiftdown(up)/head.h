#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _arr;
	int _size;
	int _capacity;
}Heap;

void Swap(HPDataType* arr, int left, int right);

void heapCreat(Heap* hp, HPDataType* arr, int size);

void shiftDown(HPDataType* arr, int size, int parent);

void shiftUp(HPDataType* arr, int child);

