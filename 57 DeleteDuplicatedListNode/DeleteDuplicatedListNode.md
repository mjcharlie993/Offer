# 删除链表中重复的结点
## 题目
> 在一个排序的链表中，如何删除重复的结点
## 参考代码
```C++
void deleteDuplication(ListNode** pHead)
{
    if (pHead == NULL || *pHead == NULL)
        return;
    ListNode* pPreNode = NULL;
    ListNode* pNode = *pHead;
    while (pNode != NULL)
    {
        ListNode *pNext = pNode->m_pNext;
        bool needDelete = false;
        if (pNext != NULL && pNext->m_nValue == pNode->m_nValue)
            needDelete = true;
        if (!needDelete)
        {
            pPreNode = pNode;
            pNode = pNode->m_pNext;
        }
        else
        {
            int value = pNode->m_nValue;
            ListNode* pToBeDel = pNode;
            while (pToBeDel != NULL && pToBeDel->m_nValue == value)
            {
                pNext = pToBeDel->m_pNext;
                delete pToBeDel;
                pToBeDel = NULL;
                pToBeDel = pNext;
            }
            if (pPreNode == NULL)
                *pHead = pNext;
            else
                pPreNode->m_pNext = pNext;
            pNode = pNext;
        }
    }
}
```