ListNode* MeetingNode(ListNode* pHead)
{
    if (pHead == NULL)
        return NULL;
    ListNode* pSlow = pHead->m_pNext;
    if (pSlow == NULL)
        return NULL;
    ListNode* pFast = pSlow->m_pNext;
    while (pFast != NULL && pSlow != NULL)
    {
        if (pFast == pSlow)
            return pFast;
        pSlow = pSlow->m_pNext;
        pFast = pFast->m_pNext;
        if (pFast != NULL)
            pFast = pFast->m_pNext;
    }
    return NULL;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    ListNode* meetingNode = MeetingNode(pHead);
    if (meetingNode == NULL)
        return NULL;
    int nodesInLoop = 1;
    ListNode* pNode1 = meetingNode;
    while (pNode1->m_pNext != meetingNode)
    {
        pNode1 = pNode1->m_pNext;
        ++nodesInLoop;
    }
    pNode1 = pHead;
    for (int i = 0; i < nodesInLoop;  ++i)
        pNode1 = pNode1->m_pNext;
    ListNode* pNode2 = pHead;
    while (pNode1 != pNode2)
    {
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }
    return pNode1;
}