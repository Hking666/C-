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

// ��ʼ��
void StackInit(SeqStack* ps, size_t capacity);

// ����
void StackDestory(SeqStack* ps);

// ѹջ
void StackPush(SeqStack* ps, STDataType x);
// ��ջ
void StackPop(SeqStack* ps);

//ջ��
STDataType StackTop(SeqStack* ps);
int StackEmpty(SeqStack* ps);
int StackSize(SeqStack* ps);

void Test();


#endif