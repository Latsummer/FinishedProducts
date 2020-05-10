#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<memory.h>



void swap(int* arr, int left, int right);
void printarr(int* arr, int size);
void insert_Sort(int* arr, int size);//��������
void shell_Sort(int* arr, int size);//ϣ������
void select_Sort(int* arr, int size);//ѡ������
void select2_Sort(int* arr, int size);//ѡ�������Ż���
void shiftDown(int* arr, int size, int parent);
void heap_Sort(int* arr, int size);//������
void bubble_Sort(int* arr, int size);//ð������
int partion(int* arr, int begin, int end);//hora����
int partion2(int* arr, int begin, int end);//�ڿӷ�
int partion3(int* arr, int begin, int end);//ǰ��ָ�뷨
void quick_Sort(int* arr, int begin, int end);//��������
void quick_Sort_NoR_Stack(int* arr, int size);//ջʵ�ַǵݹ�
void quick_Sort_NoR_Queue(int* arr, int size);//����ʵ�ַǵݹ�
void merge_Sort(int* arr, int size);//�鲢����
void count_Sort(int* arr, int size);//�������򣬷ǱȽ�