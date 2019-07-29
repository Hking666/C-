#pragma once
#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct
{	
	char name[50];
	int age;
	double height;

}LTDataType;

typedef struct ListNode
{
	LTDataType  data ;
	struct ListNode * next, *pre;

}DNode , * DListLink;

typedef struct List
{
	DNode * phead;//头指针
	
}List;

void ListInit(List *plist); // 初始化单链表
void ListDestory(List *plist); // 销毁链表
int IsEmptyDList(List *plist);  //判断链表是否为空 
int GetLenDList(List *plist);//获取链表长度
DNode * CreatNode(DNode **p, char name[50], int age, double height); // 创建节点
void DListPushFront(List * plist, char name[50], int age, double height); // 头插
void DListPushBack(List * plist, char name[50], int age, double height); //尾插法
void DListPopBack(List * plist); //删除尾节点
void DListPopFront(List * plist); //删除头节点
DNode * DListFind(List * plist, char name[50], int age, double height); // 查找指定的链表
void DListInsert(DNode * pos, char name[50], int age, double height); // 在pos前面插入节点
void DListErase(DNode * pos); // 删除pos位置上的节点
void DListRemove(List * plist, char name[50], int age, double height); // 删除第一个该值的节点
void DListRemoveALL(List * plist, char name[50], int age, double height); // 删除所有该值的节点
void ListPrint(List * plist); // 打印
