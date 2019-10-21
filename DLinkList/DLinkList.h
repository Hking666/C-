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
	DNode * phead;//ͷָ��
	
}List;

void ListInit(List *plist); // ��ʼ��������
void ListDestory(List *plist); // ��������
int IsEmptyDList(List *plist);  //�ж������Ƿ�Ϊ�� 
int GetLenDList(List *plist);//��ȡ������
DNode * CreatNode(DNode **p, char name[50], int age, double height); // �����ڵ�
void DListPushFront(List * plist, char name[50], int age, double height); // ͷ��
void DListPushBack(List * plist, char name[50], int age, double height); //β�巨
void DListPopBack(List * plist); //ɾ��β�ڵ�
void DListPopFront(List * plist); //ɾ��ͷ�ڵ�
DNode * DListFind(List * plist, char name[50], int age, double height); // ����ָ��������
void DListInsert(DNode * pos, char name[50], int age, double height); // ��posǰ�����ڵ�
void DListErase(DNode * pos); // ɾ��posλ���ϵĽڵ�
void DListRemove(List * plist, char name[50], int age, double height); // ɾ����һ����ֵ�Ľڵ�
void DListRemoveALL(List * plist, char name[50], int age, double height); // ɾ�����и�ֵ�Ľڵ�
void ListPrint(List * plist); // ��ӡ
