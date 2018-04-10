# 27 二叉搜索树与双向链表
## 题目
> 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
## 思路
1. 中序遍历+递归
2. 指定一个链表末尾指针保存中序遍历时当前结点的前一个结点
3. 把树分为三个部分：根结点、左子树、右子树，然后把左子树中最大的结点、根节点、右子树中最小的结点连接起来

## 参考代码
```C++
BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
    BinaryTreeNode* pLastNodeInList = NULL;
    ConvertNode(pRootOfTree, &pLastNodeInList);
    BinaryTreeNode* pHeadOfList = pLastNodeInList;
    while (pHeadOfList != NULL && pHeadOfList->m_pLeft != NULL)
        pHeadOfList = pHeadOfList->m_pLeft;
    return pHeadOfList;
}

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
    if (pNode == NULL)
        return;
    BinaryTreeNode* pCurrent = pNode;
    if (pCurrent->m_pLeft != NULL)
        ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
    pCurrent->m_pLeft = *pLastNodeInList;
    if (*pLastNodeInList != NULL)
        (*pLastNodeInList)->m_pRight = pCurrent;
    *pLastNodeInList = pCurrent;
    if (pCurrent->m_pRight != NULL)
        ConvertNode(pCurrent->m_pRight, pLastNodeInList);
}
```