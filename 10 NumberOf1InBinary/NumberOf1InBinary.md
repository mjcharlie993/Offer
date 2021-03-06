# 10 二进制中1的个数
## 题目
> 请实现一个函数，输入一个整数，输出该数二进制中1的个数。例如把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。
## 分析
* 利用位运算来求二进制中1的个数。
## 思路
1. 给定一个临时变量1利用&运算用来逐低位到高位检测输入整数中1的个数。每检测一位该临时变量左移1位。
2. 把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0。那么一个整数的二进制表示中有多少个1，就可以进行多少次这样的操作。
## 参考代码
思路1：
```C++
int NumberOf1(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while (flag)
    {
        if (n & 1)
            count++;
        flag = flag << 1;
    }
    return count;
}
```
思路2：
```C++
int NumberOf1(int n)
{
    int count = 0;
    while (n)
    {
        ++count;
        n = (n - 1) & n;
    }
    return count;
}

```

## 相关题目
> 用一句语句判断一个整数是不是2的整数次方

利用上述代码，如果count=1，则该整数是2的整数次方。

> 输入两个整数m和n，计算需要改变m的二进制表示中的多少位才能得到n。

1. 求这两个数的异或
2. 统计异或结果中1的位数

