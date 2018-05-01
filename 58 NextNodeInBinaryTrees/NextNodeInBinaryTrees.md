# 58 二叉树的下一个结点
## 题目
> 给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点
## 思路
1. 如果一个结点有右子树，那么它的下一个结点就是它的右子树中的最左子结点
2. 如果一个结点没有右子树
    1. 如果结点是它父结点的左子结点，那么它的下一个结点就是它的父结点
    2. 如果结点是它父结点的右子节点，那么就沿着指向父结点的指针一直向上遍历，直到找到一个是它父结点的左子结点的结点，如果这个结点存在，那么这个结点的父结点就是我们要找的下一个结点

## 参考代码
```C++
BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
    if (pNode == NULL)
        return NULL;
    BinaryTreeNode* pNext == NULL;
    if (pNode->m_pRight)
    {
        BinaryTreeNode* pRight = pNode->m_pRight;
        while (pRight->m_pLeft)
            pRight = pRight->m_pLeft;
        pNext = pRight;
    }
    else
    {
        if (pNode->m_pParent != NULL)
        {
            BinaryTreeNode* pCurrent = pNode;
            BinaryTreeNode* pParent = pNode->m_pParent;
            while (pParent && pParent->m_pRight == pCurrent)
            {
                pCurrent = pParent;
                pParent = pParent->m_pParent;
            }
            pNext = pParent;
        }
    }
    return pNext;
}
```