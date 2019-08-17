#include"heap.h"
int main56()
{
	Heap hp;
	int n = 10;//数组长度
	int pos = 0;
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	//int a[] = { 29,72,48,53,45,30,18,36,13,35 };
	HeapInit(&hp, a, n);
	Heapprintf(&hp, n);
	//adjustdown(&hp, pos);
	//HeapPush(&hp, 5);
	//adjustdown(&hp, pos);
	//Heapprintf(&hp, n);
	//
	//HeapPop(&hp);
	//Heapprintf(&hp, n);
	//Heapprintf(&hp, n);
    HeapSort(&hp, pos);
	Heapprintf(&hp, n);
    system("pause");
    return 0;
}