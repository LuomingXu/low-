#ifndef __JUDGE_H__
#define __JUDGE_H__
void da(int* array, int *array1, int i, int* count);

void xiao(int* array, int *array1, int N, int* count)
{			//������----��������---�����鳤��----����
	int i = 0;
	int j = 0;

	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (*(array + i) > *(array + j))//����������ж�������Ϊ-1
			{
				*(array1 + i) = -1;
				break;
			}
		}
		if (*(array1 + i) != -1)
		{
			(*count)++;
			da(array, array1, i, count);//����Ļ���������һ���жϣ�����count++
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
			(*count)--;//���������count--��
			return;
		}
	}
}
#endif // !__JUDGE_H__
