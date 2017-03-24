#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void da(int* array, int *array1, int i, int* count);
void xiao(int* array, int *array1, int N, int* count);
void quick_sort(int s[], int left, int right);


int main(int argc, const char* argv[])
{
	int* array;
	int* array1;
	int N = 0;
	int i = 0;
	int j = 0;
	int count = 0;//计数

	scanf_s("%d", &N);
	array = (int*)malloc(sizeof(int)*N);
	array1 = (int*)malloc(sizeof(int)*N);

	//输入
	for ( i = 0; i < N; i++)
	{
		scanf_s("%d", &array[i]);
		*(array1 + i) = 0;
	}

	//判断
	xiao(array,array1, N, &count);
	for ( i = 0; i < N; i++)
	{
		if (*(array1 + i) == -1)
			*(array + i) = -1;
	}
	free(array1);

	array1 = (int*)malloc(sizeof(int)*count);
	j = 0;
	for ( i = 0; i < N; i++)
	{
		if (*(array+i) != -1)
		{
			*(array1 + j) = *(array + i);
			j++;
		}
	}

	quick_sort(array1, 0, count-1);

	//打印输出
	printf("%d\n", count);
	for ( i = 0; i < count-1; i++)
	{
		printf("%d ", *(array1 + i));
	}
	printf("%d", *(array1+ i));
	printf("\n");

	free(array1);
	free(array);
	system("pause");
	return 0;
}

void xiao(int* array,int *array1,int N,int* count)
{
	int i = 0;
	int j = 0;
	
	for (i = 0; i < N; i++)
	{
		for (j = i+1; j < N; j++)
		{
			if (*(array + i) > *(array + j))
			{
				*(array1 + i) = -1;
				break;
			}
		}
		if (*(array1 + i) != -1)
		{
			(*count)++;
			da(array, array1, i, count);
		}
	}
	

}

void da(int* array, int *array1, int i, int* count)
{
	int j = 0;

		for (j = 0; j < i; j++)
		{
			if (*(array + i) < *(array + j))
			{
				*(array1 + i) = -1;
				(*count)--;
				return;
			}
		}
}

void quick_sort(int s[], int left, int right)
{
	if (left < right)
	{
		//Swap(s[left], s[(left + right) / 2]); //将中间的这个数和第一个数交换 参见注1  
		int i = left, j = right, x = s[left];
		while (i < j)
		{
			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数  
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数  
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s, left, i - 1); // 递归调用   
		quick_sort(s, i + 1, right);
	}
}