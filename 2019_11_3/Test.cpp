#include <iostream>
using namespace std;

// ������ģ�����
// C++11: array

namespace bite
{
	template<class T, size_t N> // N�����о��г���
	class array
	{
	public:
		void push_back(const T& data)
		{
			// N = 10;
			_array[_size++] = data;
		}

		T& operator[](size_t index)
		{
			assert(index < _size);
			return _array[index];
		}

		bool empty()const
		{
			return 0 == _size;
		}

		size_t size()const
		{
			return _size;
		}
	private:
		T _array[N];
		size_t _size;
	};
}



int main()
{
	int a = 10;
	int b = 20;

	// ������ģ����������ڱ�����ȷ������
	//bite::array<int, a+b> arr; // �ٱ����ڼ��޷�ȷ��a+b��ֵ
	bite::array<int, 10 + 20> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	return 0;
}

