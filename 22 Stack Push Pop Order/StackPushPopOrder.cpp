bool isPopOrder(const int* pPush, const int* pPop, int nLength)
{
    bool bPossible = false;
    if (pPush != NULL && pPop != NULL && nLength > 0)
    {
        const int* pNextPush = pPush;
        const int* pNextPop = pPop;
        std::stack<int> stackData;
        while (pNextPop - pPop < nLength)
        {
            while (stackData.empty() || stackData.top() != *pNextPop)
            {
                if (pNextPush - pPush == nLength)
                    break;
                stackData.push(*pNextPush);
                pNextPush++;
            }

            if (stackData.top() != *pNextPop)
                break;
            stackData.pop();
            pNextPop++;
        }
        if (stackData.empty() && pNextPop - pPop == nLength)
            bPossible = true;
    }
    return bPossible;
}