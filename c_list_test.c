#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"SListNode.h"

void test1()//头插
{
	SListNode *list = NULL;
	SListPushFront(&list, 1);
	SListPrint(list);
	SListPushFront(&list, 2);
	SListPrint(list);
	SListPushFront(&list, 3);
	SListPrint(list);
	SListPushFront(&list, 4);
	SListPrint(list);
	SListPushFront(&list, 5);
	SListPrint(list);
}
void test2()//头删
{
	SListNode *list = NULL;
	SListPushFront(&list, 1);
	SListPrint(list);
	SListPushFront(&list, 2);
	SListPrint(list);
	SListPushFront(&list, 3);
	SListPrint(list);
	SListPushFront(&list, 4);
	SListPrint(list);
	SListPushFront(&list, 5);
	SListPrint(list);
	printf("\n");
	SListPopFront(&list);
	SListPrint(list);
	SListPopFront(&list);
	SListPrint(list);
	SListPopFront(&list);
	SListPrint(list);
	SListPopFront(&list);
	SListPrint(list);
	SListPopFront(&list);
	SListPrint(list);
}
void test3()//尾插
{
	SListNode *list = NULL;
	SListPushBack(&list, 1);
	SListPrint(list);
	SListPushBack(&list, 2);
	SListPrint(list);
	SListPushBack(&list, 3);
	SListPrint(list);
	SListPushBack(&list, 4);
	SListPrint(list);
	SListPushBack(&list, 5);
	SListPrint(list);
}
void test4()//尾删
{
	SListNode *list = NULL;
	SListPushBack(&list, 1);
	SListPrint(list);
	SListPushBack(&list, 2);
	SListPrint(list);
	SListPushBack(&list, 3);
	SListPrint(list);
	SListPushBack(&list, 4);
	SListPrint(list);
	SListPushBack(&list, 5);
	SListPrint(list);
	printf("\n");
	SListPopBack(&list);
	SListPrint(list);
	SListPopBack(&list);
	SListPrint(list);
	SListPopBack(&list);
	SListPrint(list);
	SListPopBack(&list);
	SListPrint(list);
	SListPopBack(&list);
	SListPrint(list);
}
void test5()//查找
{
	SListNode *list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPrint(list);
	printf("\n");
	printf("%d\n", SListFind(list, 1)->_data );
	printf("%d\n", SListFind(list, 2)->_data );
	printf("%d\n", SListFind(list, 3)->_data );
	printf("%d\n", SListFind(list, 4)->_data );
	printf("%d\n", SListFind(list, 5)->_data );
	printf("%d\n", SListFind(list, 6));
}
void test6()//插入
{
	SListNode *list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPrint(list);
	printf("\n");
	SListNode *pos = SListFind(list, 3);
	SListInsest(&list, pos, 50);
	SListPrint(list);
	pos = SListFind(list, 5);
	SListInsest(&list, pos, 49);
	SListPrint(list);
	SListInsest(&list, NULL, 48);//尾插
	SListPrint(list);
	SListInsest(&list, list, 47);//头插
	SListPrint(list);
}
void test7()//删除
{
	SListNode *list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPrint(list);
	printf("\n");
	SListNode *pos = SListFind(list, 1);//头删
	SListErase(&list, pos);
	SListPrint(list);
	pos = SListFind(list, 5);//尾删
	SListErase(&list, pos);
	SListPrint(list);
	pos = SListFind(list, 3);
	SListErase(&list, pos);
	SListPrint(list);
}
void test8()//销毁
{
	SListNode *list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPrint(list);
	SListDestory(&list);
	SListPrint(list);
}int main()
{
	printf("头插测试：>\n");
	test1();
	printf("\n头删测试：>\n");
	test2();
	printf("\n尾插测试：>\n");
	test3();
	printf("\n尾删测试：>\n");
	test4();
	printf("\n查找测试：>\n");
	test5();
	printf("\n插入测试：>\n");
	test6();
	printf("\n删除测试：>\n");
	test7();
	printf("\n销毁测试：>\n");
	test8();
	system("pause");
	return 0;
}
