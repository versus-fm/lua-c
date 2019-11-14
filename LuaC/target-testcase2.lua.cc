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
    double x;
    double _t1;
    double _t0;
    double y;
    double _t2;
    double z;
    double _t6;
    main_0:
    x = 7.000000;
    _t1 = 10.000000 + x;
    _t0 = _t1 * 2.000000;
    y = _t0;
    _t2 = y - x;
    z = _t2;
    print(x);
    print(y);
    print(z);
    _t6 = z * z;
    z = _t6;
    print(z);
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
