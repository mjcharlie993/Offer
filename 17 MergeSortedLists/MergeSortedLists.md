# 17 合并两个排序的链表
## 题目
> 输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按照递增排序的。

## 思路
* 利用递归来处理每一个结点的连接。
* 对空头结点指针进行特殊判断。

## 参考代码
```C++
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
```