#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"Stack.h"

//typedef struct Stack
//{
//	DataType* _array;
//	size_t _top; //栈顶 
//	size_t _end;
//}Stack;

void StackInit(Stack* s)
{
	assert(s);
	s->_array = NULL;
	s->_end = 0;
	s->_top = 0;
}
void StackPush(Stack* s, DataType x)
{
	if (s->_top==s->_end)
	{
		size_t size = s->_end > 0 ? s->_end*2 : 3;
		s->_array = (DataType*)realloc(s->_array, sizeof(DataType)*size);
		assert(s->_array);
		s->_end = size;
	}
	s->_array[s->_top++] = x;
}
void StackPop(Stack* s)
{
	assert(s);
	if (s->_top > 0)
	{
		s->_top--;
	}
}
DataType StackTop(Stack* s)
{
	assert(s);
	return s->_array[s->_top - 1];
}
size_t StackSize(Stack* s)
{
	return s->_top;
}
int StackEmpty(Stack* s)
{
	assert(s);
	return s->_top;
}
