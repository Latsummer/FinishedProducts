#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<memory.h>



void swap(int* arr, int left, int right);
void printarr(int* arr, int size);
void insert_Sort(int* arr, int size);
void shell_Sort(int* arr, int size);
void select_Sort(int* arr, int size);
void select2_Sort(int* arr, int size);
void shiftDown(int* arr, int size, int parent);
void heap_Sort(int* arr, int size);
