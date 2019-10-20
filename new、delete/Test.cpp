#include<iostream>
using namespace std;



#if 0
//
//int main()
//{
//	int* p = (int*)malloc(sizeof(int)* 10);
//	free(p);
//	return 0;
//}

// new / delete     new[] / delete[]
// malloc/free
// ע�⣺һ��Ҫƥ��ʹ��

// 1. new��delete���Ǻ�����C++�ṩ���µĲ�����
// 2. new/new[] ֻ���������ռ����ͣ�����Ҫ�����ֽ���
// 3. new ����ľ��ǿռ�����ͣ���˲���Ҫǿת
// 4. new/new[]���Խ��г�ʼ��
// 5. new�Ľ������Ҫ�п�
// 6. 
int main()
{
	int arr[10]; // ���� �� int[10]
	// new ���뵥������Ԫ�صĿռ�---Ĭ�������new���Ŀռ��ڶ���
	int*p1 = new int;
	int*p2 = new int(10); // ��ʼ������ռ�Ϊ10

	int* p3 = new int[10];
	int* p4 = new int[10]{1,2,3,4,5,6,5,6,9,5};

	delete p1;
	delete p2;
	delete[] p3;

	return 0;
}

#endif

#if 0
//����������ͷŲ�ƥ�� ����
// 1�������������������͵Ŀռ䣬��������κκ��
int main()
{
	int* p1 = (int*)malloc(sizeof(int)* 10);
	int* p2 = (int*)malloc(sizeof(int)* 10);

	delete p1;
	delete p2;

	int*p3 = new int;
	int*p4 = new int;
	free(p3);
	delete[] p4;


	int* p5 = new int[10];
	int* p6 = new int[10];
	free(p5);
	delete p6;

	_CrtDumpMemoryLeaks();
	return 0;
}

#endif


#if 0
// 2�������Զ������Ͷ���
class Test
{
public:
	Test()
	{
		_data = 10;
		_p = new int;
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		delete _p;
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
	int* _p;
};

// �����Զ������ͣ�ֻҪ�漰��[]����Ȼ�����
// new����ù��캯��
// free���������������--�����е���Դ���ᱻ����
void Test2()
{
	//Test* p3 = new Test;
	//Test* p4 = new Test;
	//free(p3);
	//delete[] p4;


	// malloc����ռ�ʱ������ù��캯��--�������������С��ͬ��һ���ڴ�ռ�
	//             ���ܽ��ÿ��ڴ�ռ俴����һ������

	Test* p1 = (Test*)malloc(sizeof(Test));
	//Test* p2 = (Test*)malloc(sizeof(Test));
	delete p1;   // ��Ҫ��������������������е���Դ
	//delete[] p2;



	//Test* p5 = new Test[10];
	//Test* p6 = new Test[10];
	//free(p5);
	//delete p6;
}

int main()
{
	//Test1();
	Test2();
	_CrtDumpMemoryLeaks();
	return 0;
}

#endif


#if 0
class Test
{
public:
	Test()
	{
		_data = 10;
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
};

int main()
{
	Test* pt1 = new Test; //������ռ��ٵ��ù��캯��
	 
	Test* pt2 = new Test[10];
	delete pt1;
	delete[] pt2;
	return 0;
}

#endif


void* operator new(size_t size)
{

	return malloc(size);
}
int main()
{
	int* p = new int;
	delete(p);
	return 0;
}