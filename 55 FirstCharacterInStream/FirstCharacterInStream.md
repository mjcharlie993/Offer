# 字符流中第一个不重复的字符
## 题目
> 请实现一个函数用来找出字符流中第一个只出现一次的字符

## 思路
1. 利用哈希表存储字符及其出现次数，判断字符流中的字符即可

## 参考代码
```C++
class CharStatistics
{
public:
    CharStatistics() : index(0)
    {
        for (int i = 0; i < 256; ++i)
            occurrence[i] = -1;
    }
    void Insert(char ch)
    {
        if (occurrence[ch] == -1)
            occurrence[ch] = index;
        else if (occurrence[ch] >= 0)
            occurrence[ch] = -2;
        ++index;
    }
    char FirstAppearingOnce()
    {
        char ch = '\0';
        int minIndex = numeric_limits<int>::max();
        for (int i = 0; i < 256; ++i)
        {
            if (occurrence[i] >= 0 && occurrence[i] < minIndex)
            {
                ch = (char)i;
                minIndex = occurrence[i];
            }
        }
        return ch;
    }
    int occurrence[256];
    int index;
};
```