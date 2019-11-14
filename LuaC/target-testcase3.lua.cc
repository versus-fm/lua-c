#include <iostream>
#include <cmath>
#include <string>

void print(std::string text);
void print(double val);
void iowrite(std::string text);
void iowrite(double val);
double ioread(std::string text);
int main()
{
    double _t1;
    double n;
    double factorial;
    double x;
    double i;
    bool _t2;
    double _t3;
    main_0:
    print("enter a number:");
    _t1 = ioread("*number");
    n = _t1;
    factorial = 1.000000;
    x = 1.000000;
    i = 2.000000;
    goto main_2;
    main_2:
    _t2 = i<=n;
    if(_t2) goto main_3;
    if(!_t2) goto main_1;
    main_1:
    iowrite("factorial of ");
    iowrite(n);
    iowrite(" is ");
    print(x);
    return int();
    main_3:
    _t3 = x * i;
    x = _t3;
    i = i + 1.000000;
    goto main_2;
}
void print(std::string text)
{
    std::cout << text << std::endl;
}
void print(double val)
{
    std::cout << val << std::endl;
}
void iowrite(std::string text)
{
    std::cout << text;
}
void iowrite(double val)
{
    std::cout << val;
}
double ioread(std::string text)
{
    double d;
    std::cin >> d;
    std::cin.clear();
    return d;
}
