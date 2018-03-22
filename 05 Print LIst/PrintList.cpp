#include "PrintList.h"
#include <stack>
#include <cstdio>
// using stack.
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
// using recurse
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