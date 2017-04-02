#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include"judge.h"

void quick_sort(int* s, int left, int right);
void Read(int* array, int* array1, int N);

clock_t start, finish;
double duration;

int main(int argc, const char* argv[])//�ĳɴ��ļ��Ӷ�ȡ��������
{
	int* array;
	int* array1;
	int temp[10000];
	int N = 0;
	int i = 0;
	int j = 0;
	int count = 0;//����

	start = clock();

	FILE* fp;//��ȡ���ĸ���
	fopen_s(&fp, "c:\\wenjian.txt", "r");
	if (fp)
	{
		printf("���ڶ�ȡ\"N\"\n");
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
		printf("�޷���\n");
	}
	printf("N:%d\n", N);

	array = (int*)malloc(sizeof(int)*N);
	array1 = (int*)malloc(sizeof(int)*N);

	Read(array, array1, N);//��ȡ��������

	//�ж�
	xiao(array,array1, N, &count);

	if (count != 0)//��һһ����û��
	{
		for (i = 0; i < N; i++)
		{
			if (*(array1 + i) == -1)
				*(array + i) = -1;//��ԭʼ��ֵ�в���Ҫ�ĸ�ֵΪ-1
		}
		free(array1);

		array1 = (int*)malloc(sizeof(int)*count);
		j = 0;
		//��ԭʼ��ֵ���������ĸ�ֵ���µ�����������
		for (i = 0; i < N; i++)
		{
			if (*(array + i) != -1)
			{
				*(array1 + j) = *(array + i);
				j++;
			}
		}
		free(array);

		quick_sort(array1, 0, count - 1);//����

		//���
		printf("%d\n", count);
		for (i = 0; i < count - 1; i++)
		{
			printf("%d ", *(array1 + i));
		}
		printf("%d", *(array1 + i));
		printf("\n");
	}
	else
		printf("û��������\n");

	free(array1);

	{	//ʱ�����
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
		//Swap(s[left], s[(left + right) / 2]); //���м��������͵�һ�������� �μ�ע1  
		int i = left;
		int j = right;
		int x = *(s + left);
		while (i < j)
		{
			while (i < j && *(s+j) >= x) // ���������ҵ�һ��С��x���� 
				j--;
			if (i < j)
				*(s + (i++)) = *(s + j);
			while (i < j && *(s+i) < x)// ���������ҵ�һ�����ڵ���x���� 
				i++;
			if (i < j)
				*(s + (j--)) = *(s + i);
		}
		*(s+i) = x;
		quick_sort(s, left, i - 1); // �ݹ����   
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
		printf("�޷���\n");
	}
}