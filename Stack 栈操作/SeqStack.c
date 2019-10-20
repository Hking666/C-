#include"SeqStack.h"

void SeqStackInit(SeqStack* ps, size_t capacity)
{
	ps->array = (STDataType*)calloc(capacity, sizeof(STDataType));
	if (ps)
	{
		ps->_size = 0;
		ps->_capacity = capacity;
	}

}


void SeqStackDestory(SeqStack* ps)
{
	if (ps->array)
	{
		free(ps->array);
		ps->array = NULL;
		ps->_capacity = 0;
		ps->_size = 0;
		
	}

}

void CheckCapacity(SeqStack* ps)
{
	if (ps->_size >= ps->_capacity)
	{
		ps->_capacity = 2 * ps->_capacity + 1;
		ps->array = (STDataType *)realloc(ps->array, ps->_capacity * sizeof(STDataType));
	}


}
void StackPush(SeqStack* ps, STDataType x)
{
	CheckCapacity(ps);
	ps->array[ps->_size] = x;
	ps->_size++;

}

void StackPop(SeqStack* ps)
{

	if (StackEmpty(ps))
	{
		ps->_size--;
	}

}

int StackEmpty(SeqStack* ps)
{
	if (0 == ps->_size)
	{
		return 0;
	}
	return 1;
}

STDataType StackTop(SeqStack* ps)
{
	if (StackEmpty(ps))
	{
		return ps->array[ps->_size - 1];
	}

	return (STDataType)0;

}

int StackSize(SeqStack* ps)
{
	return ps->_size;
}

void Test()
{
	SeqStack s;
	SeqStack* p = &s;

	SeqStackInit(p, 1);
	StackPush(p, 2);
	StackPush(p, 3);
	StackPush(p, 4);
	StackPush(p, 5);
	StackPush(p, 6);
	StackPush(p, 6);
	
	printf("top == %d\n", StackTop(p));
	StackPop(p);
	printf("top == %d\n", StackTop(p));
	StackPop(p);
	printf("top == %d\n", StackTop(p));
	StackPop(p);
	printf("top == %d\n", StackTop(p));


}