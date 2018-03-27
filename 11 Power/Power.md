# 11 数值的整数次方
## 题目
> 实现函数double Power(double base, int exponent),求base的exponent次方，不得使用库函数，同时不需要考虑大数问题。
## 注意
* 若指数为负，这是需要判断底数不为零。
* double型数与0的大小关系判断（精度计算）。
## 参考代码
1. 常规解法
```C++
bool g_InvalidInput = false;

double Power(double base, int exponent)
{
    g_InvalidInput = false;
    if (equal(base, 0.0) && exponent < 0)
    {
        g_InvalidInput = true;
        return 0.0;
    }
    unsigned int absExponent = (unsigned int)(exponent);
    if (exponent < 0)
        absExponent = (unsigned int)(-exponent);
    double result = PowerWithUnsignedExponent(base, absExponent);
    if (exponent < 0)
        result = 1.0 / result;
    return result;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    double result = 1.0;
    for (int i = 1; i <= exponent; ++i)
        result *= base;
    return result;
}

bool equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001)) 
        return true;
    else
        return false;
}
```
2. 判断指数的奇偶性递归计算，优化算法。
```C++
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;
    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if (exponent & 0x1 == 1)
        result *= base;
    return result;
}
```