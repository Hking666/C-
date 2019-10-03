#include <iostream>

int Sum(int left = 0, int right = 0)
{
    return left+right;
}

double Sum(double left=0,double right=0)
{
    std::cout<<"double ";
    return left+right;
}

int main()
{
   // std::cout<<Sum(1.2,2)<<std::endl;
    return 0;
}
