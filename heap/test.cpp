#include<stdio.h>
#include<stdlib.h>
#define INIT_ARRAY_SIZE 50
//网上的对照
int heap_size; //堆大小
int heap_cap_size;  //堆容量大小

/*函数声明*/
//构建堆
void build_heap(int array[], int length);
//堆的调整
void max_heap_adjust(int array[], int index);
//堆的删除
void heap_delete(int array[], int value);
//堆的插入
void heap_insert(int** array, int value);
//堆排序
void heap_sort(int array[], int length);

/*返回以index为根的完全二叉树的左子树的索引，整个二叉树索引以0为开始*/
int left(int index) {
	return ((index << 1) + 1);
}
/*返回以index为根的完全二叉树的右子树的索引，整个二叉树索引以0为开始*/
int right(int index) {
	return ((index << 1) + 2);
}
/*两个数的交换*/
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void build_heap(int array[], int length) {
	heap_size = length;
	for (int i = ((heap_size - 1) >> 1); i >= 0; --i) {
		max_heap_adjust(array, i);
	}
}

void max_heap_adjust(int array[], int index) {//index是位置
	int left_index = left(index);
	int right_index = right(index);
	int largest = index;
	//左子树和父节点进行对比
	if (left_index <= (heap_size - 1) && array[left_index] > array[largest]) {
		largest = left_index;
	}
	//右子树和父节点进行对比
	if (right_index <= (heap_size - 1) && array[right_index] > array[largest]) {
		largest = right_index;
	}
	if (largest == index) {
		/*判断是否要进行递归调用，没交换一次最小二叉树的时候，可能会破坏前面已经调整好的堆
		的结构，所以交换一次需要从当前父亲节点开始重新进行自顶向下算法，重新调整堆*/
		/*这里的递归退出条件是左右子树下标都大于二叉树的总长度，即调整不能调整为止
		*/
		return;
	}
	else {
		//需要交换
		swap(&array[index], &array[largest]);
		//递归调用
		max_heap_adjust(array, largest);
	}
}

void heap_delete(int array[], int value) {
	int index = 0;
	for (index = 0; index < heap_size; index++) {
		if (array[index] == value) {
			break;
		}
	}
	array[index] = array[heap_size - 1];
	--heap_size;
	max_heap_adjust(array, index);
}

void heap_insert(int** array, int value) {
	int index = 0;
	int parent_index = 0;
	if (heap_size + 1 > heap_cap_size) {
		*array = (int*)realloc(*array, 2 * INIT_ARRAY_SIZE * sizeof(int));
	}
	(*array)[heap_size] = value; //一定要记得加上()既(*array)[heap_size] 如果写出*array[heap_size]肯定会出问题
	index = heap_size;
	heap_size++;//要记得这里堆大小变大了
	//和父节点对比，哪个大就往上移动
	while (index) {
		parent_index = ((index - 1) >> 1);
		if ((*array)[parent_index] < (*array)[index]) {
			swap(&((*array)[parent_index]), &((*array)[index]));
		}
		index = parent_index;
	}
}

void heap_sort(int array[], int length) {
	int old_heap_size = heap_size;
	int i;
	for (i = length - 1; i >= 1; --i) {
		swap(&array[i], &array[0]);
		--heap_size;
		max_heap_adjust(array, 0);
	}
	//恢复堆的大小
	heap_size = old_heap_size;
}
 

void print_array(int* a, int length) {
	for (int i = 0; i < length; i++) {
		printf("%d\t", a[i]);
		if (0 == i || 2 == i || 6 == i)
		{
			printf("\n");
		}
	}
	printf("\n");
}
int main() {
	int i = 0;
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	int *array = NULL;
	array = (int *)malloc(INIT_ARRAY_SIZE * sizeof(int));
	int length = sizeof(a) / sizeof(int);
	printf("数组的长度是:%d\n", length);
	for (i = 0; i < length; ++i) {
		array[i] = a[i];
	}
	printf("原始数组为\n");
	print_array(array, length);
	printf("堆的建立后的数组\n");
	build_heap(array, length);
	print_array(array, length);
	printf("堆排序后的数组为\n");
	heap_sort(array, length);
	print_array(array, length);
	//这个地方一定要记得先构建堆，不然下面执行删除和插入有问题
	build_heap(array, length);

	printf("删除数据15后的数组\n");
	heap_delete(array, 15);
	length--;
	print_array(array, length);

	printf("插入数据15后的数组\n");
	length++;
	heap_insert(&array, 15);
	print_array(array, length);

	printf("堆排序后的数组为\n");
	heap_sort(array, length);
	print_array(array, length);
	system("pause");
	return 0;
}
