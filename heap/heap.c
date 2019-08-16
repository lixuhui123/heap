//#include "heap.h"
//void adjustdown(Heap* hp, int n)
//{
//	//向下调整算法，需要的是树还有起始点下标
//	//小堆
//	int cur = n;
//	int tmp;
//	int m;
//	while (cur * 2 + 1 < hp->size)
//	{
//		if (cur * 2 + 2 >= hp->size)
//		{
//			n = cur * 2 + 1;
//		}
//		else
//		{
//			if (hp->data[cur * 2 + 1] > hp->data[cur])
//			{
//			}
//			else
//			{
//
//			}
//		}
//		if (hp->data[cur])
//		{
//		}
//	}
//}

#include "heap.h"
void adjustdown(Heap* hp, int n)
{
	//向下调整算法，需要的是树还有起始点下标
	//小堆
	int cur = n;
	int tmp;
	//int m;
	while (cur * 2 + 1 < hp->size)
	{
		if (cur * 2 + 2 >= hp->size)
		{
			//有左孩子没有右孩子
			if (hp->data[cur*2+1]>hp->data[cur])
			{

			}
			else
			{
				tmp = hp->data[cur];
				hp->data[cur] = hp->data[cur * 2 + 1];
				hp->data[cur * 2 + 1] = tmp;
				cur = cur * 2 + 1;
				 
			}
			 
		}

		
		do 
		{
			//此处既有左孩子又有右孩子
					//判断左孩子
			if (hp->data[cur * 2 + 1] > hp->data[cur])
			{
				//左孩子大于父亲
				
			}
			else
			{
				//要的是小堆此处应该交换
				tmp = hp->data[cur];
				hp->data[cur] = hp->data[cur * 2 + 1];
				hp->data[cur * 2 + 1] = tmp;
				cur = cur * 2 + 1;
				break;
			}
			//判断右孩子
			if (hp->data[cur * 2 + 2] > hp->data[cur])
			{

			}
			else
			{
				tmp = hp->data[cur];
				hp->data[cur] = hp->data[cur * 2 + 2];
				hp->data[cur * 2 + 2] = tmp;
				cur = cur * 2 + 2;
				break;
			}
		} while (0);
		
	}
}
void HeapInit(Heap* hp, HPDataType* a, int n)
{
	//初始化操作用数组赋值
	hp->size = 0;
	hp->capacity = 2 * n;
	hp->data = (HPDataType*)malloc(2*n * sizeof(HPDataType));
	for (int i=0;i<n;++i)
	{
		hp->data[i] = a[i];
		hp->size++;
	}
}
void Heapprintf(Heap* hp, int n)
{
	//1 3 7
	int tmp = 0;

	for (int i=0;i<hp->size;++i)
	{
		printf("%d ", hp->data[i]);
		if (0==i||2==i||6==i)
		{
			printf("\n");
		}

	}
	printf("\n");
}
void HeapPush(Heap* hp, HPDataType x)
{
	//按照堆插入的算法思想在插入之前应该确定被插入的堆是大堆还是小堆，先实现小堆,下标
	int tmp = 0;
	
	hp->data[hp->size] = x;
	
	int cur = hp->size;
	hp->size++;
	//printf("%d\n", hp->data[cur]);
	/*printf("%d\n", hp->data[cur - 1]);
	printf("%d\n", hp->data[(cur / 2) - 1]);*/
	while (cur != 0)//10 4 1 0
	{
		if (hp->data[cur ] < hp->data[(cur -1) /2])
		{
			tmp = hp->data[cur ];
			hp->data[cur ] = hp->data[(cur -1) /2];
			hp->data[(cur -1) /2] = tmp;
			cur = (cur -1) /2;
		}
		else
		{
			cur = (cur - 1) / 2;
		}
	}

	
}
void HeapPop(Heap* hp)
{
//删除数据是删除堆顶的数据，方法是交换堆顶和堆的最后一个数据，然后删除最后一个数据
//再进行自顶向下算法
	//交换并删除
	int tmp = 0;
	tmp = hp->data[0];
	hp->data[0] = hp->data[hp->size - 1];
	hp->data[hp->size - 1] = tmp;
	hp->size--;
	//自顶向下算法
	adjustdown(hp, 0);

}
void HeapSort(Heap* hp, int n)
{

	//方法：将堆头和每个叶子节点交换，每交换一次执行一次自顶向下算法
	//一个偶数堆非叶子节点的个数是n/2，叶子节点的个数是n/2个
	//一个奇数堆非叶子节点的个数是n/2，叶子节点的个数是n/2+1个，基于c语言的除法
	int tag = hp->size;
	if (tag%2==1)
	{
		//奇数个
		 
		for (int i=0;i< hp->size /2+1;++i)
		{
			int tmp = 0;
			tmp = hp->data[0];
			hp->data[0] = hp->data[tag - 1];
			hp->data[tag - 1] = tmp;
			adjustdown(hp, 0);
			tag--;
		}
	}
	else
	{
		//偶数个
		for (int i = 0; i < hp->size / 2; ++i)
		{
			int tmp = 0;
			tmp = hp->data[0];
			hp->data[0] = hp->data[tag - 1];
			hp->data[tag - 1] = tmp;
			adjustdown(hp, 0);
			tag--;
		}
	}

}