# 01.赋值运算符

## 关注点

* 返回值类型声明为该类型的引用，并且函数结束前返回实例自身的引用（连续赋值）。
* 传入的形参声明为常量引用。
* 释放实例自身已有的内存。
* 判断传入的参数和当前的实例（*this）是否为同一个实例。

## 经典解法
* 完成上述4条注意但未考虑内存不足导致new char抛出异常
```C++
// Junior
CMyString& CMyString::operator=(const CMyString& rhs)
{
    if (this == &rhs)
        return *this;
    delete[] m_pData;
    m_pData = NULL;
    m_pData = new char[strlen(rhs.m_pData) + 1];
    strcpy(m_pData, rhs.m_pData);
    return *this;
}
```
## 高级解法
>> 在经典解法中在分配内存前先用delete释放了实例m_pData的内存。如果此时内存不足会导致new char抛出异常，m_pData将是一个空指针，这样很容易造成程序崩溃。
>> 为了保证异常安全性，我们先创建一个临时实例，再交换临时实例和原来的实例。
* 考虑异常安全性，在分配内存成功后再释放原来的内存
```C++
CMyString& CMyString::operator=(const CMyString& rhs)
{
    if (this == &rhs)
        return *this;
    char* pTemp = new char[strlen(rhs.m_pData) + 1];
    delete[] m_pData;
    m_pData = NULL;
    m_pData = pTemp;
    strcpy(m_pData, rhs.m_pData);
    return *this;
}
```
* 创建临时实例,交换临时实例与原来的实例
```C++
// Senior
CMyString& CMyString::operator=(const CMyString& rhs)
{
    if (this != &rhs)
    {
        CMyString tempStr(rhs);
        char* pStr = tempStr.m_pData;
        tempStr.m_pData = m_pData;
        m_pData = pStr;
    }
    return *this;
}
```
