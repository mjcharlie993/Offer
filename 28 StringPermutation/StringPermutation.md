# 28 字符串的排列
## 题目
> 输入一个字符串，打印出该字符串中字符的所有排列。
## 思路
1. 把字符串分成两部分，一部分是字符串的第一个字符，另一部分是第一个字符以后的所有字符。
2. 把第一个字符和它后面的字符逐个交换
3. 递归这个过程
## 参考代码
```C++
void Permutation(char* pStr)
{
    if (pStr == NULL)
        return;
    Permutation(pStr, pStr);
}

void Permutation(char* pStr, char* pBegin)
{
    if (*pBegin == '\0')
    {
        printf("%s\n", pStr);
    }
    else
    {
        for(char* pCh = pBegin; *pCh != '\0'; ++pCh)
        {
            swap(pCh, pBegin);
            Permutation(pStr, pBegin+1);
            swap(pCh, pBegin);
        }
    }
}

void swap(char* s, char* p)
{
    char temp = *s;
    *s = *p;
    *p = temp;
}
```