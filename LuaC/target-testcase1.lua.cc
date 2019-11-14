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
    double _t6;
    double _t5;
    double _t4;
    double _t7;
    double _t3;
    double _t8;
    double _t2;
    double _t1;
    main_0:
    _t6 = 4.000000 * 2.000000;
    _t5 = pow(2.000000, _t6);
    _t4 = _t5 + 10.000000;
    _t7 = 2.000000 * 6.000000;
    _t3 = _t4 - _t7;
    _t8 = 1.000000 / 4.000000;
    _t2 = _t3 + _t8;
    _t1 = _t2 * 2.000000;
    print(_t1);
    return int();
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
