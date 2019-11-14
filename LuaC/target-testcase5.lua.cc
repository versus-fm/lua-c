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
    double *list = new double[15];
    double _t0;
    double itemCount;
    bool hasChanged;
    double _t2;
    double i;
    bool _t3;
    double _t5;
    double _t7;
    double _t6;
    bool _t4;
    double _t8;
    double _t10;
    double _t9;
    double _t11;
    bool _t1;
    double _t13;
    bool _t12;
    double _t15;
    main_0:
    list[(int)(14)] = 5.000000;
    list[(int)(13)] = 97.000000;
    list[(int)(12)] = 8.000000;
    list[(int)(11)] = 7.000000;
    list[(int)(10)] = 6.000000;
    list[(int)(9)] = 15.000000;
    list[(int)(8)] = 2.000000;
    list[(int)(7)] = 14.000000;
    list[(int)(6)] = 9.000000;
    list[(int)(5)] = 2.500000;
    list[(int)(4)] = 2.300000;
    list[(int)(3)] = 2.400000;
    list[(int)(2)] = 1.000000;
    list[(int)(1)] = 6.000000;
    _t0 = 14;
    itemCount = _t0;
    goto main_3;
    main_3:
    hasChanged = false;
    _t2 = itemCount - 1.000000;
    itemCount = _t2;
    i = 1.000000;
    goto main_5;
    main_5:
    _t3 = i<=itemCount;
    if(_t3) goto main_6;
    if(!_t3) goto main_4;
    main_6:
    _t5 = list[(int)(i)];
    _t7 = i + 1.000000;
    _t6 = list[(int)(_t7)];
    _t4 = _t5>_t6;
    if(_t4) goto main_8;
    if(!_t4) goto main_7;
    main_7:
    i = i + 1.000000;
    goto main_5;
    main_8:
    _t8 = list[(int)(i)];
    _t10 = i + 1.000000;
    _t9 = list[(int)(_t10)];
    list[(int)(i)] = _t9;
    _t11 = i + 1.000000;
    list[(int)(_t11)] = _t8;
    hasChanged = true;
    goto main_7;
    main_4:
    goto main_2;
    main_2:
    _t1 = hasChanged==false;
    if(_t1) goto main_1;
    if(!_t1) goto main_3;
    main_1:
    i = 1.000000;
    goto main_10;
    main_10:
    _t13 = 14;
    _t12 = i<=_t13;
    if(_t12) goto main_11;
    if(!_t12) goto main_9;
    main_9:
    return int();
    main_11:
    _t15 = list[(int)(i)];
    print(_t15);
    i = i + 1.000000;
    goto main_10;
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
