# 26 复杂链表的复制
## 题目
> 请实现函数ComplexListNode* Clone(ComplexListNode* pHead),复制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个结点外，还有一个m_pSibling指向链表中的任意结点或者NULL
## 思路
* 无辅助空间
1. 根据原始链表中的每一个结点创建其副本，并连接在每个原始结点之后。
2. 复制Sibling指针给每一个新创建的副本。
3. 将原始链表与新的链表副本拆分。

* 有辅助空间
1. 利用map来存储原始链表结点与副本链表结点的对应值。
2. 通过map很容易找到Sibling指针在副本链表中的指向。
3. 用空间换时间。
## 参考代码
```C++
struct ComplexListNode
{
    int m_nValue;
    ComplexListNode* m_pNext;
    ComplexListNode* m_pSibling;
};

ComplexListNode* Clone(ComplexListNode* pHead)
{
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);

}

void CloneNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while (pNode != NULL)
    {
        ComplexListNode* pCloned = new ComplexListNode();
        pCloned->m_nValue = pNode->m_nValue;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = NULL;
        pNode->m_pNext = pCloned;
        pNode = pCloned->m_pNext;
    }
}

void ConnectSiblingNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while (pNode != NULL)
    {
        ComplexListNode* pCloned = pNode->m_pNext;
        if  (pNode->m_pSibling != NULL)
            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
        pNode = pCloned->m_pNext;
    }
}

ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    ComplexListNode* pClonedHead = NULL;
    ComplexListNode* pClonedNode = NULL;
    if (pNode != NULL)
    {
        pClonedHead = pClonedNode = pNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    while (pNode != NULL)
    {
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    return pClonedHead;
}
```