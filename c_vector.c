#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"SeqList.h"


void SeqPrint(SeqList* pSeq)//打印
{
	assert(pSeq);
	int i = 0;
	for (; i < pSeq->_size; i++)
	{
		printf("%d ", pSeq->_a[i]);
	}
	printf("\n");
}
void SeqInit(SeqList* pSeq)/*初始化*/
{
	assert(pSeq);
	pSeq->_a = 0;
	pSeq->_size = 0;
	pSeq->_capacity = 0;
}
void SeqDestory(SeqList* pSeq)/*销毁*/
{
	assert(pSeq);
	pSeq->_a = 0;
	pSeq->_size = 0;
	pSeq->_capacity = 0;
	free(pSeq);
	pSeq = NULL;
}

void SeqPushBack(SeqList* pSeq, DataType x)//尾插
{
	if (pSeq->_capacity == pSeq->_size)
	{
		pSeq->_a = (DataType*)realloc(pSeq->_a, sizeof(DataType)*(pSeq->_capacity * 2 + 3));
		pSeq->_capacity = pSeq->_capacity>0 ? pSeq->_capacity * 2 : 3;
	}
	pSeq->_size++;
	pSeq->_a[pSeq->_size-1] = x;
}
void SeqPopBack(SeqList* pSeq)//尾删
{
	assert(pSeq);
	assert(pSeq->_size);
		pSeq->_size--;
}
void SeqPushFront(SeqList* pSeq, DataType x)//头插
{
	assert(pSeq);
	int i = 0;
	if (pSeq->_capacity == pSeq->_size)
	{
		pSeq->_a = (DataType*)realloc(pSeq->_a, sizeof(DataType)*(pSeq->_capacity * 2 + 3));
		pSeq->_capacity = pSeq->_capacity>0 ? pSeq->_capacity * 2:3;
		pSeq->_size++;
		for (i = pSeq->_size - 1; i > 0; i--)
		{
			pSeq->_a[i] = pSeq->_a[i - 1];
		}
		pSeq->_a[0] = x;
	}
	else
	{
		pSeq->_size++;
		for (i = pSeq->_size - 1; i > 0; i--)
		{
			pSeq->_a[i] = pSeq->_a[i - 1];
		}
		pSeq->_a[0] = x;
	}
}
void SeqPopFront(SeqList* pSeq)//头删
{
	assert(pSeq);
	assert(pSeq->_size);
	int i = 0;
	for (; i < pSeq->_size - 1; i++)
	{
		pSeq->_a[i] = pSeq->_a[i + 1];
	}
	pSeq->_size--;
}

void SeqInsert(SeqList* pSeq, size_t pos, DataType x)//插入
{
	assert(pSeq);
	assert(pos < pSeq->_size);
	int i = pSeq->_size;
	if (pSeq->_capacity == pSeq->_size)
	{
		pSeq->_a = (DataType*)realloc(pSeq->_a, sizeof(DataType)*(pSeq->_capacity * 2 + 3));
		pSeq->_capacity = pSeq->_capacity>0 ? pSeq->_capacity * 2 : 3;
	}
	pSeq->_size++;
	for (; i > pos; i--)
	{
		pSeq->_a[i] = pSeq->_a[i - 1];
	}
	pSeq->_a[pos] = x;
}
void SeqErase(SeqList* pSeq, size_t pos)//删除
{
	assert(pSeq);
	assert(pSeq->_size);
	assert(pos < pSeq->_size);
	int i = pos;
	for (; i < pSeq->_size -1; i++)
	{
		pSeq->_a[i] = pSeq->_a[i + 1];
	}
	pSeq->_size--;
}

int SeqFind(SeqList* pSeq, DataType x)//查找
{
	assert(pSeq);
	assert(pSeq->_size);
	int i = 0;
	for (i = 0; i < pSeq->_size; i++)
	{
		if (x == pSeq->_a[i])
		{
			return i;
		}
	}
	return -1;
}
void SeqAt(SeqList* pSeq, size_t pos, DataType x)//替换
{
	assert(pSeq);
	assert(pos < pSeq->_size);
	pSeq->_a[pos] = x;
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void BubbleSort(SeqList* pSeq)//冒泡排序
{
	assert(pSeq);
	assert(pSeq->_size);
	int i = 0;
	int j = pSeq->_size - 1;
	for (; j >= 0; j--)
	{
		int count = 0;
		for (i = 0; i < j; i++)
		{
			if (pSeq->_a[i]>pSeq->_a[i + 1])
			{
				count = 1;
				Swap(&(pSeq->_a[i]), &(pSeq->_a[i + 1]));
			}
		}
		if (count == 0)
		{
			break;
		}
	}
}
void SelectSort(SeqList* pSeq)//选择排序
{
	assert(pSeq);
	assert(pSeq->_size);
	int i = 0;
	int j = 0;
		for (i = pSeq->_size - 1; i >= 0; i--)
		{
			int* min = &pSeq->_a[pSeq->_size - i - 1];
			int* max = &pSeq->_a[pSeq->_size - i - 1];
			for (j = pSeq->_size - i - 1; j <= i; j++)
			{
				if (pSeq->_a[j]>*max)
				{
					max = &pSeq->_a[j];
				}
				else if (pSeq->_a[j] < *min)
				{
					min = &pSeq->_a[j];
				}
			}
			if (*min == pSeq->_a[pSeq->_size - i - 1])
			{
				if (*max == pSeq->_a[i])
				{
					break;
				}
				else
				{
					Swap(max, &pSeq->_a[i]);
				}
			}
			else if (*min == pSeq->_a[i])
			{
				if (*max == pSeq->_a[pSeq->_size - i - 1])
				{
					Swap(max, min);
				}
				else
				{
					Swap(min, &pSeq->_a[pSeq->_size - i - 1]);
					Swap(max, &pSeq->_a[i]);
				}
			}
			else if (*max == pSeq->_a[i] && *min != pSeq->_a[pSeq->_size - i - 1])
			{
				Swap(min, &pSeq->_a[pSeq->_size - i - 1]);
			}
			else if (*max == pSeq->_a[pSeq->_size - i - 1] && *min != pSeq->_a[i])
			{
				Swap(max, &pSeq->_a[i]);
				Swap(min, &pSeq->_a[pSeq->_size - i - 1]);
			}
			else
			{
				Swap(max, &(pSeq->_a[i]));
				Swap(min, &(pSeq->_a[pSeq->_size - i - 1]));
			}
		}
}
int BinarySearch(SeqList* pSeq, DataType x)//二分查找
{
	assert(pSeq);
	assert(pSeq->_size);
	int start = 0;
	int end = pSeq->_size - 1;
	while (start<=end)
	{
		int mid = (start + end) >> 1;
		if (x == pSeq->_a[mid])
		{
			return mid;
		}
		else if (x > pSeq->_a[mid])
		{
			start = mid + 1;
		}
		else if (x < pSeq->_a[mid])
		{
			end = mid - 1;
		}
	}
	return -1;
}
