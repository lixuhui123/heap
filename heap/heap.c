//#include "heap.h"
//void adjustdown(Heap* hp, int n)
//{
//	//���µ����㷨����Ҫ������������ʼ���±�
//	//С��
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
	//���µ����㷨����Ҫ������������ʼ���±�
	//С��
	int cur = n;
	int tmp;
	//int m;
	while (cur * 2 + 1 < hp->size)
	{
		if (cur * 2 + 2 >= hp->size)
		{
			//������û���Һ���
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
			//�˴��������������Һ���
					//�ж�����
			if (hp->data[cur * 2 + 1] > hp->data[cur])
			{
				//���Ӵ��ڸ���
				
			}
			else
			{
				//Ҫ����С�Ѵ˴�Ӧ�ý���
				tmp = hp->data[cur];
				hp->data[cur] = hp->data[cur * 2 + 1];
				hp->data[cur * 2 + 1] = tmp;
				cur = cur * 2 + 1;
				break;
			}
			//�ж��Һ���
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
	//��ʼ�����������鸳ֵ
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
	//���նѲ�����㷨˼���ڲ���֮ǰӦ��ȷ��������Ķ��Ǵ�ѻ���С�ѣ���ʵ��С��,�±�
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
//ɾ��������ɾ���Ѷ������ݣ������ǽ����Ѷ��Ͷѵ����һ�����ݣ�Ȼ��ɾ�����һ������
//�ٽ����Զ������㷨
	//������ɾ��
	int tmp = 0;
	tmp = hp->data[0];
	hp->data[0] = hp->data[hp->size - 1];
	hp->data[hp->size - 1] = tmp;
	hp->size--;
	//�Զ������㷨
	adjustdown(hp, 0);

}
void HeapSort(Heap* hp, int n)
{

	//����������ͷ��ÿ��Ҷ�ӽڵ㽻����ÿ����һ��ִ��һ���Զ������㷨
	//һ��ż���ѷ�Ҷ�ӽڵ�ĸ�����n/2��Ҷ�ӽڵ�ĸ�����n/2��
	//һ�������ѷ�Ҷ�ӽڵ�ĸ�����n/2��Ҷ�ӽڵ�ĸ�����n/2+1��������c���Եĳ���
	int tag = hp->size;
	if (tag%2==1)
	{
		//������
		 
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
		//ż����
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