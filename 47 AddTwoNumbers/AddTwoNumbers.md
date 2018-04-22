# 不用加减乘除做加法
## 题目
> 写一个函数，求两个整数之和，要求在函数内不得使用+、-、*、/四则运算符号

## 思路
1. 利用位运算模拟加法策略
2. 各位相加不计进位(^)
3. 记下进位(&+<<)
4. 前两步结果相加(for)

## 参考代码
```C++
int Add(int num1, int num2)
{
    int sum, carry;
    do
    {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    }
    while (num2 != 0)
    return num1;
}
```

## 相关问题
1. 不使用新变量，交换两个变量
基于加减法
```C++
a = a + b;
b = a - b;
a = a - b;
```
基于异或运算
```C++
a = a ^ b;
b = a ^ b;
a = a ^ b;
```