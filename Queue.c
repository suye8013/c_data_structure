#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"Queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->_head = q->_tail = NULL;
}
void QueuePush(Queue* q, DataType x)
{
	assert(q);
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	assert(node);
	node->_data = x;
	node->_next = NULL;
	if (q->_tail == NULL)
	{
		q->_head = q->_tail = node;
	}
	else
	{
		q->_tail->_next = node;
		q->_tail = node;
	}
}
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_head == q->_tail)
	{
		if (q->_head)
		{
			free(q->_head);
			q->_head = q->_tail = NULL;
		}
		else
		{
			Queue* tmp = q->_head->_next;
			free(q->_head);
			q->_head = tmp;
		}
	}
}
DataType QueueFront(Queue* q)
{
	assert(q);
	return q->_head->_data;
}
DataType QueueBack(Queue* q)
{
	assert(q);
	return q->_tail->_data;
}
size_t QueueSize(Queue* q)
{
	size_t size = 0;
	QueueNode* cur = q->_head;
	while (cur != q->_tail)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_head == NULL ? 0 : 1;
}
