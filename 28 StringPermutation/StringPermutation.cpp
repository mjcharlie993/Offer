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