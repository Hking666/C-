class Solution {
public:
	class C_Number
	{
	public:
		C_Number()
		{
			count++;
			sum += count;
		}
		static void ReSet()
		{
			count = 0;
			sum = 0;

		}
		static size_t GetSum()
		{
			return sum;
		}
	private:
		static size_t sum;
		static size_t count;
	};


	int Sum_Solution(int n) {

		C_Number::ReSet();  // 面对多组测试，需要对 count 、sum清零
		C_Number total[n];
		return C_Number::GetSum();
	}

};
size_t Solution::C_Number::count = 0; // 类外定义静态变量
size_t Solution::C_Number::sum = 0;
