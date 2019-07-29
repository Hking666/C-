#include"DLinkList.h"

void ListInit(List *plist) // 初始化单链表
{
	plist->phead = (DNode *)malloc(sizeof(DNode));
	plist->phead->next = plist->phead;
	plist->phead->pre = plist->phead;


}

int IsEmptyDList(List *plist) // 判空
{
	
	return plist->phead->next == plist->phead && plist->phead->pre == plist->phead ? 1 : 0;
}

void ListDestory(List *plist) // 销毁链表
{
	DNode *p = plist->phead->next;
	
	while (p != plist->phead)
	{
		p = p->next;
		free(p->pre);
		
	}
	// 指针 p 无需置空
	plist->phead->next = plist->phead;
	plist->phead->pre = plist->phead;
}

DNode * CreatNode(DNode **p, char name[50], int age, double height) // 创建节点
{
	*p = (DNode *)malloc(sizeof(DNode));
	if (*p == NULL)
	{
		printf("创建失败！\n");
		return NULL;
	}
	strcpy((*p)->data.name , name);
	(*p)->data.age = age;
	(*p)->data.height = height;

	return *p;
}

void DListPushFront(List * plist, char name[50], int age, double height)// 头插
{

	DNode *newNode = CreatNode(&newNode, name, age, height);
	if (newNode == NULL)
	{
		printf("插入失败！\n");
		return;
	}

	newNode->next = plist->phead->next;
	plist->phead->next->pre = newNode;
	plist->phead->next = newNode;
	newNode->pre = plist->phead;



}

void DListPushBack(List * plist, char name[50], int age, double height) // 尾插
{
	DNode *newNode = CreatNode(&newNode, name, age, height); 
	if (newNode == NULL)
	{
		printf("插入失败！\n");
		return;
	}
	
	newNode->pre = plist->phead->pre;
	plist->phead->pre->next = newNode;
	newNode->next = plist->phead;
	plist->phead->pre = newNode;


		
}


void DListPopBack(List * plist) //删除尾节点
{	
	if (IsEmptyDList(plist)==1)
	{
		printf("该链表为空\n");
		return;
	}

	DNode *til = plist->phead->pre;
	
	til->pre->next = plist->phead;
	plist->phead->pre = til->pre;

	free(til);
	til = NULL;
}
void DListPopFront(List * plist) //删除头节点
{
	if (IsEmptyDList(plist))
	{
		printf("该链表为空\n");
		return;
	}
	DNode *p = plist->phead->next;
	plist->phead->next = p->next;
	p->next->pre = plist->phead;
	
	
	free(p);
	p = NULL;

}

DNode * DListFind(List * plist, char name[50], int age, double height) // 查找指定的链表
{
	if (IsEmptyDList(plist))
	{
		printf("该链表为空\n");
		
	}
	DNode * p = plist->phead->next;
	while (p != plist->phead )
	{ 
		if (strcmp(p->data.name, name) == 0 && p->data.age == age && p->data.height == height)
		{
			return p;
	     }
		p = p->next;

	}
	return NULL;
	
	
}



void ListPrint(List * plist) // 打印
{
	DNode * p = plist->phead->next;
	
	while (p != plist->phead)
	{
		printf("%s\n", p->data.name);
		printf("%d\n", p->data.age);
		printf("%lf\n", p->data.height);
		p = p->next;

	}

}

void DListErase(DNode * pos)// 删除pos位置上的节点
{
	
	pos->pre->next = pos->next;
	pos->next->pre = pos->pre;
	free(pos);
	pos = NULL;
}

void DListInsert(DNode * pos, char name[50], int age, double height) // 在pos前面进行插入
{
	DNode * newNode = CreatNode(&newNode, name, age, height);
	
	if (newNode == NULL)
	{
		printf("插入失败！\n");
		return;
	}
	newNode->next = pos->next;
	pos->pre->next = newNode;
	newNode->pre = pos->pre;
	pos->next->pre = newNode;


}

void DListRemove(List * plist, char name[50], int age, double height) // 删除第一个值的节点
{
	if (IsEmptyDList(plist))
	{
		printf("该链表为空\n");
		return;
	}

	DNode * p = plist->phead->next;
	while (p != plist->phead)
	{
		if (strcmp(p->data.name, name) == 0 && p->data.age == age && p->data.height == height)
		{
			p->pre->next = p->next;
			p->next->pre = p->pre;
			free(p);
			p = NULL;
			return ;
		}
		p = p->next;

	}
	printf("该节点不存在！");
	

}


void DListRemoveALL(List * plist, char name[50], int age, double height) // 删除所有该值的节点
{
	if (IsEmptyDList(plist))
	{
		printf("该链表为空\n");
		return;
	}

	DNode * p = plist->phead->next;
	while (p != plist->phead)
	{
		if (strcmp(p->data.name, name) == 0 && p->data.age == age && p->data.height == height)
		{
			p->pre->next = p->next;
			p->next->pre = p->pre;

			DNode * node = p;
			p = p->next;
			free(node);
			node = NULL;

			continue;
		}
		p = p->next;

	}


}