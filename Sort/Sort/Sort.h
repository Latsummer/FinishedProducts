#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<memory.h>



void swap(int* arr, int left, int right);
void printarr(int* arr, int size);
void insert_Sort(int* arr, int size);//插入排序
void shell_Sort(int* arr, int size);//希尔排序
void select_Sort(int* arr, int size);//选择排序
void select2_Sort(int* arr, int size);//选择排序（优化）
void shiftDown(int* arr, int size, int parent);
void heap_Sort(int* arr, int size);//堆排序
void bubble_Sort(int* arr, int size);//冒泡排序
int partion(int* arr, int begin, int end);//hora划分
int partion2(int* arr, int begin, int end);//挖坑法
int partion3(int* arr, int begin, int end);//前后指针法
void quick_Sort(int* arr, int begin, int end);//快速排序
void quick_Sort_NoR_Stack(int* arr, int size);//栈实现非递归
void quick_Sort_NoR_Queue(int* arr, int size);//队列实现非递归
void merge_Sort(int* arr, int size);//归并排序
void count_Sort(int* arr, int size);//计数排序，非比较