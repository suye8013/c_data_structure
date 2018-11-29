#ifndef __STACK_H__
#define __STACK_H__

typedef int DataType;

typedef struct Stack
{
	DataType* _array;
	size_t _top; //栈顶 
	size_t _end;
}Stack;

void StackInit(Stack* s);
void StackPush(Stack* s, DataType x);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
size_t StackSize(Stack* s);
int StackEmpty(Stack* s);

#endif
