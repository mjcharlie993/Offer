struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};

ListNode* ReverseList(ListNode* pHead)
{
    ListNode* pReversedHead = NULL;
    ListNode* pNode = pHead;
    ListNode* pPrev = NULL;
    while (pNode != NULL)
    {
        ListNode* pNext = pNode->m_pNext;
        if (pNext == NULL)
            pReversedHead = pNode;
        pNode->m_pNext = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
    return pReversedHead;
}


class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL || pHead->next == NULL)
        {
            return pHead;
        }
        else
        {
            ListNode* pNewNode = ReverseList(pHead->next);
            pHead->next->next = pHead;
            pHead->next = NULL;
            return pNewNode;
        }
    }
};