#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>
#include"SListNode.h"
SListNode* BuySListNode(DataType x)//申请节点 已测
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode)*2+3);
	newNode->_data = x;
	newNode->_next = NULL;
	return newNode;
}
void SListPrint(SListNode* pHead)//打印链表 已测
{
	if (pHead == NULL)
	{
		printf("这是一个空链表！！！\n");
		return;
	}
	SListNode* prev = pHead;
	while (prev != NULL)
	{
		printf("%d ", prev->_data);
		prev = prev->_next;
	}
	printf("\n");
}
void SListDestory(SListNode** ppHead)//销毁链表 已测
{
	assert(ppHead);
	SListNode* prev = *ppHead;
	while ((*ppHead) != NULL)
	{
		prev = prev->_next;
		free(*ppHead);
		*ppHead = prev;
	}
}

void SListPushBack(SListNode** ppHead, DataType x)//尾插 已测
{
	assert(ppHead);
	SListNode* newNode;
	if (*ppHead == NULL)
	{
		*ppHead = BuySListNode(x);
		return;
	}
	SListNode* prev = *ppHead;
	while (prev->_next != NULL)
	{
		prev = prev->_next;
	}
	newNode = BuySListNode(x);
	prev->_next = newNode;
}
void SListPopBack(SListNode** ppHead)//尾删 已测
{
	assert(ppHead);
	if ((*ppHead)->_next == NULL)
	{
		free(*ppHead);
		*ppHead = NULL;
		return;
	}
	SListNode* prac = *ppHead;
	SListNode* prev = *ppHead;
	while (prac->_next != NULL)
	{
		prev = prac;
		prac = prac->_next;
	}
	prev->_next = NULL;
	free(prac);
}
void SListPushFront(SListNode** ppHead, DataType x)//头插 已测
{
	assert(ppHead);
	if (*ppHead == NULL)
	{
		*ppHead = BuySListNode(x);
		return;
	}
	SListNode* prev = BuySListNode(x);
	prev->_next = *ppHead;
	*ppHead = prev;
}
void SListPopFront(SListNode** ppHead)//头删 已测
{
	assert(ppHead);
	if ((*ppHead)->_next==NULL)
	{
		free(*ppHead);
		*ppHead = NULL;
		return;
	}
	SListNode* prev = *ppHead;
	*ppHead = prev->_next;
	free(prev);
}
SListNode* SListFind(SListNode* pHead, DataType x)//查找 已测
{
	assert(pHead);
	SListNode* prev = pHead;
	while (x != prev->_data)
	{
		if (prev->_next == NULL)
		{
			printf("找不到\n");
			return -1;
		}
		else
		{
			prev = prev->_next;
		}
	}
	return prev;
}
void SListInsest(SListNode** ppHead, SListNode* pos, DataType x)//插入 已测
{
	assert(ppHead);
	SListNode* newNode;
	SListNode* prev = *ppHead;
	if (pos == *ppHead)
	{
		SListNode* prev = BuySListNode(x);
		prev->_next = *ppHead;
		*ppHead = prev;
		return;
	}
	while (prev->_next != pos)
	{
		prev = prev->_next;
	}
	newNode = BuySListNode(x);
	prev->_next = newNode;
	newNode->_next = pos;
}
void SListErase(SListNode** ppHead, SListNode* pos)//删除 已测
{
	assert(*ppHead&&pos);
	if (pos == *ppHead)
	{
		if ((*ppHead)->_next == NULL)
		{
			free(*ppHead);
			*ppHead = NULL;
			return;
		}
		SListNode* prev = *ppHead;
		*ppHead = prev->_next;
		free(prev);
		return;
	}
	if (pos->_next  == NULL)
	{
		if ((*ppHead)->_next == NULL)
		{
			free(*ppHead);
			*ppHead = NULL;
			return;
		}
		SListNode* prac = *ppHead;
		SListNode* prev = *ppHead;
		while (prac->_next != NULL)
		{
			prev = prac;
			prac = prac->_next;
		}
		prev->_next = NULL;
		free(prac);
		return;
	}
	SListNode* prev = *ppHead;
	while ((*ppHead)->_next != pos)
	{
		prev = *ppHead;
		*ppHead = (*ppHead)->_next;
	}
	prev->_next = pos->_next;
	free(pos);
}
