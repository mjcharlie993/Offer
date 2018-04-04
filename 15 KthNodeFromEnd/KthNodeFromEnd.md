# 链表中倒数第k个结点
## 题目
> 输入一个链表，输出该链表中倒数第k个结点。
## 思路
1. 遍历两次链表，第一次统计链表中元素的个数，第二次顺序遍历到第n-k+1个元素即可
2. 利用双指针，第一个指针先遍历到k-1个结点，此时两个指针同时开始遍历，直到第一个指针遍历结束，这时第二个指针所指的元素就是链表中倒数第k个结点。
3. 将链表结点放去栈中，然后弹出的第k个元素就是链表中倒数第k个结点。

## 鲁棒性
1. 给定链表是否为空。
2. 给定k值是否为0.
3. k是否超过链表的总元素数。

## 参考代码
```C++
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    if (pListHead == NULL || k == 0)
        return NULL;
    ListNode* pAhead = pListHead;
    ListNode* pBehind = NULL;
    for (int i = 0; i < k - 1; ++i)
    {
        if (pAhead->m_pNext != NULL)
            pAhead = pAhead->m_pNext;
        else
            return NULL;
    }
    pBehind = pListHead;
    while (pAhead->m_pNext != NULL)
    {
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    return pBehind;
}
```
## 相关题目
1. 求链表的中间结点。如果链表中结点总数为奇数，返回中间结点；如果结点总数为偶数，返回中间结点的任意一个
```C++
ListNode* midNode(ListNode* pListHead)
{
    if (pListNode == NULL)
        return;
    ListNode* fast = pListHead;
    ListNode* slow = pListHead;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
```
2. 判断一个单向链表是否形成了环状结构
```C++
bool hasCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return false;
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}
```
