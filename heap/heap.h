#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* data;
	int size;//ÔªËØ¸öÊý
	int capacity;
}Heap;
void adjustdown(Heap* hp, int n);
void HeapInit(Heap* hp, HPDataType* a, int n);
//void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
//HPDataType HeapTop(Heap* hp);
//int HeapSize(Heap* hp);
//int HeapEmpty(Heap* hp);
// ¶ÑÅÅÐò
void HeapSort(Heap* hp, int n);
//void TestHeap();
void Heapprintf(Heap* hp,int n);