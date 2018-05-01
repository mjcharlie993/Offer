# 59 对称的二叉树
## 题目
> 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的
## 思路
1. 定义一个前序遍历的对称遍历算法，即先遍历右子结点再遍历左子结点

## 参考代码
```C++
bool isSymmetrical(BinaryTreeNode* pRoot)
{
    return isSymmetrical(pRoot, pRoot);
}

bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    if (pRoot1 == NULL && pRoot2 == NULL)
        return true;
    if (pRoot1 == NULL || pRoot2 == NULL)
        return false;
    if (pRoot1->m_nValue != pRoot2->m_nValue)
        return false;
    return isSymmetrical(pRoo1->m_pLeft, pRoot2->m_pRight) && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}
```