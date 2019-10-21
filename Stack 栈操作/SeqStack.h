#ifndef SEQSTACK_H
#define SEQSTACK_H

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#pragma warning (disable:4996)

#define MAX_SIZE 1024

typedef int  STDataType;
typedef struct Stack
{
	STDataType* array;
	int _size;
	int _capacity;


} SeqStack;

// ³õÊ¼»¯
void StackInit(SeqStack* ps, size_t capacity);

// Ïú»Ù
void StackDestory(SeqStack* ps);

// Ñ¹Õ»
void StackPush(SeqStack* ps, STDataType x);
// ³öÕ»
void StackPop(SeqStack* ps);

//Õ»¶¥
STDataType StackTop(SeqStack* ps);
int StackEmpty(SeqStack* ps);
int StackSize(SeqStack* ps);

void Test();


#endif