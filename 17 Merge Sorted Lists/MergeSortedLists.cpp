ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == NULL)
        return pHead2;
    else if (pHead2 == NULL)
        return pHead1;
    ListNode* pMergeHead = NULL;
    if (pHead1->val < pHead2->val)
    {
        pMergeHead = pHead1;
        pMergeHead->next = Merge(pHead1->next, pHead2);
    }
    else
    {
        pMergeHead = pHead2;
        pMergeHead->next = Merge(pHead1, pHead2->next);
    }
    return pMergeHead;
}