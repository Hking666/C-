#include <iostream>

namespace huang1
{
    int a;
    int b;

    int Sum(int a ,int b)
    {
        return a+b;
    }
}

namespace huang2
{
    int c;
    int d;

    int Add(int c, int d)
    {
        return c+d;
    }

    namespace huang1
    {
        int a;
        int b;

    }
}

using huang1::a;
int main()
{
    a = 10;
    std::cout<<huang1::a<<std::endl;
    huang2::huang1::a = 20;
    std::cout<<huang2::huang1::a<<std::endl;
    return 0;
} 
