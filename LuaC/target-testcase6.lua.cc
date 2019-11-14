#include <iostream>
#include <cmath>
#include <string>

void print(std::string text);
void print(double val);
void iowrite(std::string text);
void iowrite(double val);
double ioread(std::string text);
double fibonacci(double n);
double fibonacci(double n)
{
    bool _t0;
    double _t3;
    double _t5;
    double _t1;
    double _t2;
    double _t4;
    fibonacci_0:
    _t0 = n<3.000000;
    if(_t0) goto fibonacci_3;
    if(!_t0) goto fibonacci_4;
    fibonacci_4:
    _t3 = n - 1.000000;
    _t2 = fibonacci(_t3);
    _t5 = n - 2.000000;
    _t4 = fibonacci(_t5);
    _t1 = _t2 + _t4;
    return _t1;
    goto fibonacci_2;
    fibonacci_2:
    
    return double();
    fibonacci_3:
    return 1.000000;
    goto fibonacci_2;
}
int main()
{
    double n;
    bool _t6;
    double _t8;
    double _t2;
    double _t4;
    main_0:
    n = 1.000000;
    goto main_6;
    main_6:
    _t6 = n<=16.000000;
    if(_t6) goto main_7;
    if(!_t6) goto main_5;
    main_7:
    _t8 = fibonacci(n);
    iowrite(_t8);
    iowrite(", ");
    n = n + 1.000000;
    goto main_6;
    main_5:
    iowrite("...\n");
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
