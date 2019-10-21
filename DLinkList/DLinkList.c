#include"DLinkList.h"

void ListInit(List *plist) // ��ʼ��������
{
	plist->phead = (DNode *)malloc(sizeof(DNode));
	plist->phead->next = plist->phead;
	plist->phead->pre = plist->phead;


}

int IsEmptyDList(List *plist) // �п�
{
	
	return plist->phead->next == plist->phead && plist->phead->pre == plist->phead ? 1 : 0;
}

void ListDestory(List *plist) // ��������
{
	DNode *p = plist->phead->next;
	
	while (p != plist->phead)
	{
		p = p->next;
		free(p->pre);
		
	}
	// ָ�� p �����ÿ�
	plist->phead->next = plist->phead;
	plist->phead->pre = plist->phead;
}

DNode * CreatNode(DNode **p, char name[50], int age, double height) // �����ڵ�
{
	*p = (DNode *)malloc(sizeof(DNode));
	if (*p == NULL)
	{
		printf("����ʧ�ܣ�\n");
		return NULL;
	}
	strcpy((*p)->data.name , name);
	(*p)->data.age = age;
	(*p)->data.height = height;

	return *p;
}

void DListPushFront(List * plist, char name[50], int age, double height)// ͷ��
{

	DNode *newNode = CreatNode(&newNode, name, age, height);
	if (newNode == NULL)
	{
		printf("����ʧ�ܣ�\n");
		return;
	}

	newNode->next = plist->phead->next;
	plist->phead->next->pre = newNode;
	plist->phead->next = newNode;
	newNode->pre = plist->phead;



}

void DListPushBack(List * plist, char name[50], int age, double height) // β��
{
	DNode *newNode = CreatNode(&newNode, name, age, height); 
	if (newNode == NULL)
	{
		printf("����ʧ�ܣ�\n");
		return;
	}
	
	newNode->pre = plist->phead->pre;
	plist->phead->pre->next = newNode;
	newNode->next = plist->phead;
	plist->phead->pre = newNode;


		
}


void DListPopBack(List * plist) //ɾ��β�ڵ�
{	
	if (IsEmptyDList(plist)==1)
	{
		printf("������Ϊ��\n");
		return;
	}

	DNode *til = plist->phead->pre;
	
	til->pre->next = plist->phead;
	plist->phead->pre = til->pre;

	free(til);
	til = NULL;
}
void DListPopFront(List * plist) //ɾ��ͷ�ڵ�
{
	if (IsEmptyDList(plist))
	{
		printf("������Ϊ��\n");
		return;
	}
	DNode *p = plist->phead->next;
	plist->phead->next = p->next;
	p->next->pre = plist->phead;
	
	
	free(p);
	p = NULL;

}

DNode * DListFind(List * plist, char name[50], int age, double height) // ����ָ��������
{
	if (IsEmptyDList(plist))
	{
		printf("������Ϊ��\n");
		
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



void ListPrint(List * plist) // ��ӡ
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

void DListErase(DNode * pos)// ɾ��posλ���ϵĽڵ�
{
	
	pos->pre->next = pos->next;
	pos->next->pre = pos->pre;
	free(pos);
	pos = NULL;
}

void DListInsert(DNode * pos, char name[50], int age, double height) // ��posǰ����в���
{
	DNode * newNode = CreatNode(&newNode, name, age, height);
	
	if (newNode == NULL)
	{
		printf("����ʧ�ܣ�\n");
		return;
	}
	newNode->next = pos->next;
	pos->pre->next = newNode;
	newNode->pre = pos->pre;
	pos->next->pre = newNode;


}

void DListRemove(List * plist, char name[50], int age, double height) // ɾ����һ��ֵ�Ľڵ�
{
	if (IsEmptyDList(plist))
	{
		printf("������Ϊ��\n");
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
	printf("�ýڵ㲻���ڣ�");
	

}


void DListRemoveALL(List * plist, char name[50], int age, double height) // ɾ�����и�ֵ�Ľڵ�
{
	if (IsEmptyDList(plist))
	{
		printf("������Ϊ��\n");
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