# 13 在O(1)时间删除链表节点
## 题目
> 给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结点。
## 思路
* 顺序查找，找到要删除的结点后，将结点前一结点的指针指向待删除结点的后一个结点，删除待删除结点即可。
* 覆盖查找，找到删除结点，将该结点下一个结点的值赋值给该结点，删除下一个结点即可。

## 参考代码
```C++
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if (!pListHead || !pToBeDeleted)
        return;
    if (pToBeDeleted->next != NULL)
    {
        ListNode* Next = pToBeDeleted->next;
        pToBeDeleted->val = Next->val;
        pToBeDeleted->next = Next->next;
        delete Next;
        Next = NULL;
    }
    else if (*pListHead == pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        *pListHead = NULL;
    }
    else
    {
        ListNode* Node = *pListHead;
        while (Node->next != pToBeDeleted)
        {
            Node = Node->next;
        }
        Node->next = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}
```