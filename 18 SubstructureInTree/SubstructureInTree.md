# 18 树的子结构
## 题目
> 输入两颗二叉树A和B，判断B是不是A的子结构。
## 思路
1. 在树A中找到和B的根节点的值一样的结点R
2. 判断A中以R为根节点的子树是不是包含和树B一样的结构

参考代码
```C++
bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    bool result = false;
    if (pRoot1 != NULL && pRoot2 != NULL)
    {
        if (pRoot1->val == pRoot2->val)
            result = DoesTree1HaveTree2(pRoot1, pRoot2);
        if (!result)
            result = HasSubtree(pRoot1->left, pRoot2);
        if (!result)
            result = HasSubtree(pRoot1->right, pRoot2);
    }
    return result;
}

bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    if (pRoot2 == NULL)
        return true;
    if (pRoot1 == NULL)
        return false;
    if (pRoot1->val != pRoot2->val)
        return false;
    return DoesTree1HaveTree2(pRoot1->left, pRoot2->left) && DoesTree1HaveTree2(pRoot1->right, pRoot2->right);
}
```