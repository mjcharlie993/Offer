# 求1+2+...+n
## 题目
> 求1+2+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句

## 解法一，利用构造函数求解
1. 循环只是让相同的代码重复执行n遍而已。
2. 如果不用for和while。可以定义一个类型，接着创建n个该类型的实例，那么这个类型的构造函数将确定会被调用n次
3. 把与累加相关的代码放在构造函数中

## 参考代码一
```C++
class Temp
{
public:
    Temp() { ++N; Sum += N; }
    static void Reset() { N = 0; Sum = 0; }
    static unsigned int GetSum() { return Sum; }
private:
    static unsigned int N;
    static unsigned int Sum;
};
unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int Sum_Solution1(unsigned int n)
{
    Temp::Reset();
    Temp *a = new Temp[n];
    delete[] a;
    a = NULL;

    return Temp::GetSum();
}
```

## 解法二：利用虚函数求解
1. 定义两个函数，一个函数充当递归函数的角色，另一个函数处理终止递归的情况
2. 对数值变量n做两个反运算，!!n那么非零的n转换为true，0转换为false。

## 参考代码二
```C++
class A;
A* Array[2];
class A
{
public:
    virtual unsigned int Sum(unsigned int n)
    {
        return 0;
    }
};
class B : public A
{
public:
    virtual unsigned int Sum(unsigned int n)
    {
        return Array[!!n]->Sum(n-1) + n;
    }
};

int Sum_Solution2(int n)
{
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;
    int value = Array[1]->Sum(n);
    return value;
}
```

## 解法三：利用函数指针求解
1. 用函数指针模拟虚函数

## 参考代码三
```C++
typedef unsigned int (*fun)(unsigned int);
unsigned int Solution3_Teminator(unsigned int n)
{
    return 0;
}
unsigned int Sum_Solution3(unsigned int n)
{
    static fun f[2] = {Solution3_Teminator, Sum_Solution3};
    return n + f[!!n][n-1];
}
```

## 解法四：利用模板类型求解

## 参考代码四
```C++
template<unsigned int n> 
struct Sum_Solution4
{
    enum Value { N = Sum_Solution4<n-1>::N + n};
};
template <> 
struct Sum_Solution4<1>
{
    enum Value {N = 1};
};
```