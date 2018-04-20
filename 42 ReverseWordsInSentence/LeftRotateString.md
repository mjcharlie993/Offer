# 42 左旋转字符串
## 题目
> 字符串的左旋转操作就是把字符串前面的若干个字符转移到字符串的尾部
## 思路
1. 把字符串分成了两个部分，如“abcdefg”->“ab”，“cdefg”，分别翻转两个部分
2. 得到"ba","gfedc"，将这两部分拼接后翻转即可

## 参考代码
```C++
char* LeftRotateString(char* pStr, int n)
{
    if (pStr != NULL)
    {
        int nLength = static_cast<int>(strlen(pStr));
        if (nLength > 0  && n > 0 && nLength > n)
        {
            char* pFirstStart = pStr;
            char* pFirstEnd = pStr + n - 1;
            char* pSecondStart = pStr + n;
            char* pSecondEnd = pStr + nLength - 1;
            Reverse(pFirstStart, pFirstEnd);
            Reverse(pSecondStart, pSecondEnd);
            Reverse(pFirstStart, pSecondEnd);
        }
    }
    return pStr;
}

void Reverse(char* pBegin, char* pEnd)
{
    if (pBegin == NULL || pEnd == NULL)
        return;
    while (pBegin < pEnd)
    {
        char temp = *pBegin();
        *pBegin = *pEnd;
        *pEnd = temp;
        pBegin++;
        pEnd--;
    }
}
```