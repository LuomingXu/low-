#ifndef __JUDGE_H__
#define __JUDGE_H__
void da(int* array, int *array1, int i, int* count);

void xiao(int* array, int *array1, int N, int* count)
{			//主数组----伴随数组---主数组长度----个数
	int i = 0;
	int j = 0;

	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (*(array + i) > *(array + j))//将不满足的判断数组设为-1
			{
				*(array1 + i) = -1;
				break;
			}
		}
		if (*(array1 + i) != -1)
		{
			(*count)++;
			da(array, array1, i, count);//满足的话继续做下一个判断，并将count++
		}
		else
			continue;
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
			(*count)--;//将不满足的count--了
			return;
		}
	}
}
#endif // !__JUDGE_H__
