#include"DLinkList.h"

int main()
{

	List plist ;
	ListInit( &plist);
	DListPopBack(&plist);
	if (IsEmptyDList(&plist)==1 )
	{
		printf("¿Õ\n");
	}
	else
	{
		printf("·Ç¿Õ\n");
	}
	DListPushBack(&plist, "lili", 12, 13.56);
	DListPushFront(&plist, "huih", 19, 12.58);
	
	DListPushBack(&plist, "huahua", 15, 56.2);
	DListPushBack(&plist, "tat", 14, 125.3);
	DListPushBack(&plist, "gagg", 11, 216.2);
	DListPushBack(&plist, "pipi", 13, 26.2);
	DListPushBack(&plist, "pipi", 13, 26.2);
	DListPushBack(&plist, "pipi", 13, 26.2);
	DListPushFront(&plist, "jk", 18, 215.2);
	
	ListPrint(&plist);
	printf("***********\n");
	DListPopBack(&plist);
	DListPopFront(&plist);
	ListPrint(&plist);
	printf("*****************\n");
	DListFind(&plist, "hnhiuh", 15, 2156.2);
	DListFind(&plist, "huih", 19, 12.58);
	printf("*****************\n");
	DListRemove(&plist, "gagg", 11, 216.2);
	ListPrint(&plist);
	printf("*****************\n");
	DListRemoveALL(&plist, "pipi", 13, 26.2);
	ListPrint(&plist);
	system("pause");
	return 0;
}