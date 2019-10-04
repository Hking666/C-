#include <iostream>

int main()
{
    
    int a = 10;
    int& ra = a;
    double b = 2.2;
    double& rb = b;
    char c = 'a';
    char& rc = c;
    std::cout<<"int: "<<sizeof(ra)<<"double: "<<sizeof(rb)<<"char: "<<sizeof(rc)<<std::endl;
    std::cout<<"int&: "<<sizeof(int&)<<"double&: "<<sizeof(double&)<<"char&: "<<sizeof(char&)<<std::endl;

    ra = 20;
    std::cout<<"a: "<<a<<std::endl;
    
    int d =30;
    ra = d;
    std::cout<<"a: "<<a<<std::endl;

    int& rra = ra;
    rra = 40;

    std::cout<<"a: "<<a<<std::endl;
    std::cout<<"ra: "<<ra<<std::endl;

    const char ca = 'a';
    const int& rca = 10;//
    return 0;
}
