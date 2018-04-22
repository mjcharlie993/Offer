# 48 不能被继承的类
## 题目
> 用C++设计一个不能被继承的类

## 思路
1. 把构造函数设为私有函数
    1. 利用公有的静态函数来创建和释放类的实例
    2. 只能在堆上创建实例
2. 利用虚拟继承
    1. 可以在栈和堆上创建实例

## 参考代码
```C++
class SealedClass1
{
public:
    static SealedClass1* GetInstance()
    {
        return new SealedClass1();
    }
    static void DeleteInstance(SealedClass1* pInstance)
    {
        delete pInstance;
    }
private:
    SealedClass1() {}
    ~SealedClass1() {}
};
```
```C++
template<typename T>
class MakeSealed
{
    friend T;
private:
    MakeSealed() {}
    ~MakeSealed() {}
};
class SealedClass2 : virtual public MakeSealed<SealedClass2>
{
public:
    SealedClass2() {}
    ~SealedClass2() {}
};
```