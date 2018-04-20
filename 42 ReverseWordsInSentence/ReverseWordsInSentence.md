# 42 翻转单词顺序
## 题目
> 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。标点符号和普通字符一样处理。
## 思路
1. 两次翻转
2. 先翻转整个句子
3. 再翻转句子中的每个单词

## 参考代码
```C++
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

char* ReverseSentence(char* pData)
{
    if (pData == NULL)
        return NULL;
    char* pBegin = pData;
    char* pEnd = pData;
    while (*pEnd != '\0')
        pEnd++;
    pEnd--;
    Reverse(pBegin, pEnd);
    pBegin = pEnd = pData;
    while (*pBegin != '\0')
    {
        if (*pBegin == ' ')
        {
            pBegin++;
            pEnd++;
        }
        else if (*pEnd == ' ' || *pEnd == '\0')
        {
            Reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        }
        else
        {
            pEnd++;
        }
    }
    return pData;
}
```