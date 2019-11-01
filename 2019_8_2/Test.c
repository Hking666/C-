#include<stdio.h>
#include<windows.h>
#include<errno.h>
#pragma warning(disable:4996)

int main()
{	
	int a = 10000;
	FILE * pf1 = fopen("test.txt", "wb");
	fwrite(&a, sizeof(int), 1, pf1);
	fclose(pf1);
	pf1 = NULL;


	fputc('c', stdout); // 以字符为单位输出'c'
	


	const char *msg = "hello world\n";
	fwrite(msg, strlen(msg), 1, stdout);  // 将hello world 输出 ，  一切皆文件，包括鼠标、显示器等 

	
	FILE * pf2 = fopen("test.txt", "w");
	if (NULL == pf2)
	{
		printf("%d:%s", errno, strerror(errno)); // 将错误码转化为错误码描述
		return 1;
	}
	int pos = ftell(pf2);//文件指针相对于起始位置的偏移量，而每次下标相当于 下次要写入的位置，可以按照数组理解
	printf("pos :%d \n", pos); //0
	fputc('c', pf2);
	pos = ftell(pf2);
	printf("pos :%d \n", pos); //1

	fputc('c', pf2);
	pos = ftell(pf2);
	printf("pos :%d \n", pos); //2

	fputc('c', pf2);
	pos = ftell(pf2);
	printf("pos :%d \n", pos); //3

	fputc('c', pf2);
	pos = ftell(pf2);
	printf("pos :%d \n", pos); //4

	fputc('c', pf2);
	pos = ftell(pf2);
	printf("pos :%d \n", pos); //5

	fclose(pf2);
	
	FILE * pf3 = fopen("test.txt", "r");  //只读
	if (NULL == pf2)
	{
		printf("%d:%s\n", errno, strerror(errno)); // 将错误码转化为错误码描述
		system("pause");
		return 1;
	}

	int c = fgetc(pf3);
	printf("%c\n", c); //输出c;
	fclose(pf3);

	
	fputs("hello world!\n",stdout);   // 向显示器输出 hello world!
	FILE * pf4 = fopen("test1.txt", "w");
	if (NULL == pf2)
	{
		printf("%d:%s\n", errno, strerror(errno)); // 将错误码转化为错误码描述
		system("pause");
		return 1;
	}
	printf("pos:%d\n", ftell(pf4)); // 文件位置0 
	// 写入时，会自动将\n转换为 \r\n 所以会多一个字符
	fputs("hello world!\n", pf4); // 输出hello world! 至文件test1.txt中  hello world! \r\n (0—13 共14个字符)
	printf("pos:%d\n", ftell(pf4)); // 指向文件下一个待写入位置14
	fclose(pf4); 


	FILE * pf5 = fopen("test2.txt", "w");
	if (NULL == pf2)
	{
		printf("%d:%s\n", errno, strerror(errno)); // 将错误码转化为错误码描述
		system("pause");
		return 1;
	}
	printf("pos:%d\n", ftell(pf5)); // 文件位置0 
	const char * str = "hello";  // 二进制将 \0 转为 00  
	fwrite(str , strlen(str)+1,1,pf5);  // 二进制输入 
	printf("pos:%d\n", ftell(pf5)); // 指向文件下一个待写入位置6
	fclose(pf5);


	FILE * pf6 = fopen("test3.txt", "w");
	if (NULL == pf2)
	{
		printf("%d:%s\n", errno, strerror(errno)); // 将错误码转化为错误码描述
		system("pause");
		return 1;
	}
	printf("pos:%d\n", ftell(pf6)); // 文件位置0 
	
	fprintf(pf6, "hello world\n"); //输出hello world 至文件test3.txt中
	fprintf(stdout, "hello world\n"); // 向屏幕打印hello world
	printf("pos:%d\n", ftell(pf6)); // 指向文件下一个待写入位置6
	fclose(pf6);

	int x = 12345;
	char buf1[16];
	sprintf(buf1,"%d",x);  // 将整型转换为字符存入buf中
	int i = 0;
	for (i; i < 16; i++)
	{
		printf("%c\n", buf1[i]); // '1' '2' '3' '4' '5'
	}

	int y = 0;
	char buf2[16] = "12345";
	sscanf(buf2, "%d", &y);
	
		printf("%d\n", y);  // 12345
	
	system("pause");
	return 0;
}