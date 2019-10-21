#include<stdio.h>
#include<stdlib.h>
#define INIT_ARRAY_SIZE 50
//���ϵĶ���
int heap_size; //�Ѵ�С
int heap_cap_size;  //��������С

/*��������*/
//������
void build_heap(int array[], int length);
//�ѵĵ���
void max_heap_adjust(int array[], int index);
//�ѵ�ɾ��
void heap_delete(int array[], int value);
//�ѵĲ���
void heap_insert(int** array, int value);
//������
void heap_sort(int array[], int length);

/*������indexΪ������ȫ��������������������������������������0Ϊ��ʼ*/
int left(int index) {
	return ((index << 1) + 1);
}
/*������indexΪ������ȫ��������������������������������������0Ϊ��ʼ*/
int right(int index) {
	return ((index << 1) + 2);
}
/*�������Ľ���*/
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

void max_heap_adjust(int array[], int index) {//index��λ��
	int left_index = left(index);
	int right_index = right(index);
	int largest = index;
	//�������͸��ڵ���жԱ�
	if (left_index <= (heap_size - 1) && array[left_index] > array[largest]) {
		largest = left_index;
	}
	//�������͸��ڵ���жԱ�
	if (right_index <= (heap_size - 1) && array[right_index] > array[largest]) {
		largest = right_index;
	}
	if (largest == index) {
		/*�ж��Ƿ�Ҫ���еݹ���ã�û����һ����С��������ʱ�򣬿��ܻ��ƻ�ǰ���Ѿ������õĶ�
		�Ľṹ�����Խ���һ����Ҫ�ӵ�ǰ���׽ڵ㿪ʼ���½����Զ������㷨�����µ�����*/
		/*����ĵݹ��˳����������������±궼���ڶ��������ܳ��ȣ����������ܵ���Ϊֹ
		*/
		return;
	}
	else {
		//��Ҫ����
		swap(&array[index], &array[largest]);
		//�ݹ����
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
	(*array)[heap_size] = value; //һ��Ҫ�ǵü���()��(*array)[heap_size] ���д��*array[heap_size]�϶��������
	index = heap_size;
	heap_size++;//Ҫ�ǵ�����Ѵ�С�����
	//�͸��ڵ�Աȣ��ĸ���������ƶ�
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
	//�ָ��ѵĴ�С
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
	printf("����ĳ�����:%d\n", length);
	for (i = 0; i < length; ++i) {
		array[i] = a[i];
	}
	printf("ԭʼ����Ϊ\n");
	print_array(array, length);
	printf("�ѵĽ����������\n");
	build_heap(array, length);
	print_array(array, length);
	printf("������������Ϊ\n");
	heap_sort(array, length);
	print_array(array, length);
	//����ط�һ��Ҫ�ǵ��ȹ����ѣ���Ȼ����ִ��ɾ���Ͳ���������
	build_heap(array, length);

	printf("ɾ������15�������\n");
	heap_delete(array, 15);
	length--;
	print_array(array, length);

	printf("��������15�������\n");
	length++;
	heap_insert(&array, 15);
	print_array(array, length);

	printf("������������Ϊ\n");
	heap_sort(array, length);
	print_array(array, length);
	system("pause");
	return 0;
}
