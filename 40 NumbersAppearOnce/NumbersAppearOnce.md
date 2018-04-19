# 40 数组中只出现一次的数字
## 题目
> 一个整形数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n),空间复杂度是O(1)
## 思路
1. 如果这个数组中只有一个数字只出现一次，那么使用异或即可
2. 现在存在两个数字只出现了一次，那么将数组分为两组，每个数组中含有一个只出现一次的数字，应用异或即可
3. 如果按2的要求把数组分为两组，首先先将原数组的异或结果求出，根据这个结果中首位为1的二进制位将元素分为两个数组，这样不同的元素就被分到了两个不同的数组
4. 根据异或结果分割是因为任何一个数字异或它自己等于0，如果异或结果为1，那么说明这两个数不同。
5. 在每个数组中异或即可求出只出现一次的数字
## 参考代码
```C++
void FindNumsAppearOnce(int data[], int length, int* num1, int* num2)
{
    if (data == NULL || length < 2)
        return;
    int resultExclusiveOR = 0;
    for (int i = 0; i < length; ++i)
        resultExclusiveOR ^= data[i];
    unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);
    *num1 = *num2 = 0;
    for (int j = 0; j < length; ++j)
    {
        if (IsBit1(data[j], indexOf1))
            *num1 ^= data[j];
        else
            *num2 ^= data[j];
    }
}

unsigned int FindFirstBitIs1(int num)
{
    int indexBit = 0;
    while ((num & 1) == 0 && (indexBit < 8 * sizeof(int)))
    {
        num = num >> 1;
        ++indexBit;
    }
    return indexBit;
}

bool isBit1(int num, unsigned int indexBit)
{
    num = num >> indexBit;
    return (num & 1);
}
```