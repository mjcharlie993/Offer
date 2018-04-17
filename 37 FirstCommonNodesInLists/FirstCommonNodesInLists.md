# 37 两个链表的第一个公共结点
## 题目
> 输入两个链表，找出 它们的第一个公共结点。
## 公共结点特点
1. 从第一个公共结点开始，之后它们所有结点都是重合的，类似于Y形
2. 可以从尾部开始比较，最后一个相同的结点就是我们要找的结点
3. 先统计两个链表的长度，然后长链表先走比短链表多的长度，然后一起遍历直到出现的结点相同。

## 思路
1. 蛮力算法：时间O(mn)
2. 利用栈：时间O(m+n),空间O(m+n)
3. 利用链表长短指针：时间O(m+n)

## 参考代码3
```C++
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
```
## 相关题目
* 如果将这个含有公共结点的链表Y形，将Y旋转180°。形成类似于树形，每个指针由叶结点指向根节点，可以用于求两个结点的最低公共祖先