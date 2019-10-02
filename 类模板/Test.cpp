#include<iostream>
using namespace std;
#include <assert.h>

// 顺序表  链表  栈和队列  二叉树  堆  排序

// typedef int DataType;

//动态类型顺序表
template<class T>
class SeqList // 类模板的名字
{
public:
	SeqList(size_t capacity = 10)
		: _array(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}

	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	// 尾部
	void PushBack(const T& data);
	void PopBack()
	{
		--_size;
	}

	// 任意位置插入和删除
	//void Insert(size_t pos, const T& data);
	//void Erase(size_t pos);

	// 在const类型成员函数中不能修改成员变量
	// 修饰this指针
	size_t size()const
	{
		return _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

	////////////////////////// 下标类型访问总共有两种方式。
	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}

	const T& operator[](size_t index)const
	{
		assert(index < _size);
		return _array[index];
	}

private:
	void _CheckCapacity()
	{
		if (_size == _capacity)
		{
			// 开辟新空间
			T* array = new T[2 * _capacity];

			// 拷贝元素
			// memcpy(array, _array, _size*sizeof(T)); // 浅拷贝

			for (size_t i = 0; i < _size; ++i)
			{
				array[i] = _array[i];
			}

			// 释放旧空间
			delete[] _array;
			_array = array;
			_capacity *= 2;
		}
	}
private:
	T* _array;
	size_t _size;
	size_t _capacity;
};

// 类外实现PushBack
template<class T>
void SeqList<T>::PushBack(const T& data) // 
{
	_CheckCapacity(); // 再插入之前，先判满
	_array[_size++] = data;
}


void TestSeqList()
{
	SeqList<int>  s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	cout << s1.size() << endl;
	cout << s1.Capacity() << endl;

	cout << s1[2] << endl;
	s1[2] = 10;

	const SeqList<double>  s2; // const 不能调用普通类型的成员函数， 
	s2[0];
}

int main()
{
	TestSeqList();
	return 0;
}
