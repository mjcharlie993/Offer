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