#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include"judge.h"

void quick_sort(int* s, int left, int right);
void Read(int* array, int* array1, int N);

clock_t start, finish;
double duration;

int main(int argc, const char* argv[])//改成从文件从读取数组内容
{
	int* array;
	int* array1;
	int temp[10000];
	int N = 0;
	int i = 0;
	int j = 0;
	int count = 0;//计数

	start = clock();

	FILE* fp;//读取数的个数
	fopen_s(&fp, "c:\\wenjian.txt", "r");
	if (fp)
	{
		printf("正在读取\"N\"\n");
		for (i = 0; ; i++)
		{
			fscanf_s(fp, "%d", &temp[i]);
			if (temp[i] == -1)
				break;
			N++;
		}
		fclose(fp);
	}
	else
	{
		printf("无法打开\n");
	}
	printf("N:%d\n", N);

	array = (int*)malloc(sizeof(int)*N);
	array1 = (int*)malloc(sizeof(int)*N);

	Read(array, array1, N);//读取数组内容

	//判断
	xiao(array,array1, N, &count);

	if (count != 0)//万一一个都没有
	{
		for (i = 0; i < N; i++)
		{
			if (*(array1 + i) == -1)
				*(array + i) = -1;//将原始数值中不需要的赋值为-1
		}
		free(array1);

		array1 = (int*)malloc(sizeof(int)*count);
		j = 0;
		//将原始数值保留下来的赋值给新的数组做排序
		for (i = 0; i < N; i++)
		{
			if (*(array + i) != -1)
			{
				*(array1 + j) = *(array + i);
				j++;
			}
		}
		free(array);

		quick_sort(array1, 0, count - 1);//排序

		//输出
		printf("%d\n", count);
		for (i = 0; i < count - 1; i++)
		{
			printf("%d ", *(array1 + i));
		}
		printf("%d", *(array1 + i));
		printf("\n");
	}
	else
		printf("没有数满足\n");

	free(array1);

	{	//时间计量
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("Time:%.8fms\n", duration * 1000);
	}
	
	system("pause");
	return 0;
}

void quick_sort(int* s, int left, int right)
{
	if (left < right)
	{
		//Swap(s[left], s[(left + right) / 2]); //将中间的这个数和第一个数交换 参见注1  
		int i = left;
		int j = right;
		int x = *(s + left);
		while (i < j)
		{
			while (i < j && *(s+j) >= x) // 从右向左找第一个小于x的数 
				j--;
			if (i < j)
				*(s + (i++)) = *(s + j);
			while (i < j && *(s+i) < x)// 从左向右找第一个大于等于x的数 
				i++;
			if (i < j)
				*(s + (j--)) = *(s + i);
		}
		*(s+i) = x;
		quick_sort(s, left, i - 1); // 递归调用   
		quick_sort(s, i + 1, right);
	}
}

void Read(int* array,int* array1,int N)
{
	FILE* fp;
	fopen_s(&fp, "c:\\wenjian.txt", "r");
	int i = 0;
	if (fp)
	{
		for ( i = 0; i < N; i++)
		{
			fscanf_s(fp, "%d", (array + i));
			*(array1 + i) = 0;
		}
		fclose(fp);
	}
	else
	{
		printf("无法打开\n");
	}
}