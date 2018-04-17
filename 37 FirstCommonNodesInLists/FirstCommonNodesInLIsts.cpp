ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
    unsigned int nLength1 = GetListLength(pHead1);
    unsigned int nLength2 = GetListLength(pHead2);
    int nLengthDif = nLength1 - nLength2;
    ListNode* pListHeadLong = pHead1;
    ListNode* pListHeadShort = pHead2;
    if (nLength2 > nLength1)
    {
        pListHeadLong = pHead2;
        pListHeadShort = pHead1;
        nLengthDif = nLength2 - nLength1;
    }
    for (int i = 0; i < nLengthDif; ++i)
        pListHeadLong = pListHeadLong->next;
    while (pListHeadLong != NULL && pListHeadShort != NULL && pListHeadLong != pListHeadShort)
    {
        pListHeadLong = pListHeadLong->next;
        pListHeadShort = pListHeadShort->next;
    }
    ListNode* pFirstCommonNode = pListHeadLong;
    return pFirstCommonNode;
}

unsigned int GetListLength(ListNode* pHead)
{
    unsigned int nLength = 0;
    ListNode* pNode = pHead;
    while (pNode != NULL)
    {
        ++nLength;
        pNode = pNode->next;
    }
    return nLength;
}