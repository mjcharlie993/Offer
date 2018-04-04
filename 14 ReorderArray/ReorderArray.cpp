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
