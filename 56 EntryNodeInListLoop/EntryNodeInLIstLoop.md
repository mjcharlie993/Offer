# 链表中环的入口结点
## 题目
> 一个链表中包含环，如何找出环的入口结点

## 思路
1. 先定义两个指针p1和p2指向链表的头结点。
2. 如果链表中的环有n个结点，指针p1先在链表上向前移动n步，然后两个指针以相同的速度向前移动。至第二个指针指向环的入口结点时，第一个指针已经围绕着环走了一圈又回到了入口结点。
3. 针对如何得到环中结点数。两个指针相遇的结点一定是在环中，可以从这个结点出发，一边继续向前移动一边计数，当再次回到这个结点时，就可以得到环中结点数

## 参考代码
```C++
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
```