# 14 调整数组顺序使奇数位于偶数前面
## 题目
> 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分
## 思路
* 利用双指针。前向指针指向偶数，后向指针指向奇数时交换两个数即可，直到两个指针相遇。
## 参考代码
```C++
void ReorderOddEven(int* pData, unsigned int length)
{
    if (pData == NULL || length <= 0)
        return;
    int* pBegin = pData;
    int* pEnd = pData + length - 1;
    while (pBegin < pEnd)
    {
        while (pBegin < pEnd && (*pBegin & 0x1) != 0)
            pBegin++;
        while (pBegin < pEnd && (*pEnd & 0x1) == 0)
            pEnd--;
        if (pBegin < pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}
```
为了增强该算法的拓展性，引入函数指针。使该算法框架可以将数组分割的条件更加抽象
```C++
void Reorder(int *pData, unsigned int length, bool (*func)(int))
{
    if (pData == NULL || length <= 0)
        return;
    int* pBegin = pData;
    int* pEnd = pData + length - 1;
    while (pBegin < pEnd)
    {
        while (pBegin < pEnd && !func(*pBegin))
            pBegin++;
        while (pBegin < pEnd && func(*pEnd))
            pEnd--;
        if (pBegin < pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

bool isEven(int n)
{
    return (n & 1) == 0;
}

void ReorderOddEven(int *pData, unsigned int length)
{
    Reorder(pData, length, isEven);
}

```