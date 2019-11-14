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
    double i;
    bool _t2;
    double _t5;
    bool _t4;
    main_0:
    print("enter a number:");
    _t1 = ioread("*number");
    n = _t1;
    i = 2.000000;
    goto main_2;
    main_2:
    _t2 = i<=n;
    if(_t2) goto main_3;
    if(!_t2) goto main_1;
    main_3:
    iowrite(i);
    _t5 = std::fmod(n, i);
    _t4 = _t5==0.000000;
    if(_t4) goto main_5;
    if(!_t4) goto main_6;
    main_1:
    return int();
    main_5:
    iowrite(" is a factor of ");
    goto main_4;
    main_4:
    print(n);
    i = i + 1.000000;
    goto main_2;
    main_6:
    iowrite(" is not a factor of ");
    goto main_4;
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
