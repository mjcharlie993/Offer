# 05 从尾到头打印链表
## 题目
> 输入一个链表的头结点，从尾到头反过来打印每个结点的值
## 思路
* 利用stack的FILO特性来打印链表
* 利用递归来打印链表
## 参考代码
* using stack
```C++
void PrintListReversingly_Iteratively(ListNode* pHead)
{
    std::stack<ListNode*> nodes;
    ListNode* pNode = pHead;
    while (pNode != NULL)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    while (!nodes.empty())
    {
        pNode = nodes.top();
        printf("%d\t", pNode->m_nValue);
        nodes.pop();
    }
}
```
* using recurse
```C++
void PrintListReversingly_Recursively(ListNode* pHead)
{
    if (pHead != NULL)
    {
        if (pHead->m_pNext != NULL)
        {
            PrintListReversingly_Recursively(pHead->m_pNext);
        }
        printf("%d\t", pNode->m_nValue);
    }
}
```