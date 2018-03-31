# 16 反转链表
## 题目
> 定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。

## 思路
* 如果要反转一个链表，需要定义三个指针：
1. 当前遍历到的结点（调整的结点）
2. 它的前一个结点（链接链表）
3. 它的后一个结点（防止链表断裂）
* 反转结束后返回原始链表的尾结点（当前处理结点的下一个结点为空）

## 参考代码
* 迭代
```C++
ListNode* ReverseList(ListNode* pHead)
{
    ListNode* pReversedHead = NULL;
    ListNode* pNode = pHead;
    ListNode* pPrev = NULL;
    while (pNode != NULL)
    {
        ListNode* pNext = pNode->next;
        if (pNext == NULL)
            pReversedHead = pNode;
        pNode->next = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
    return pReversedHead;
}
```
* 递归
```C++
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
```