# 39 二叉树的深度
## 题目
一、
> 输入一棵二叉树的根节点，求该树的深度。从根结点到叶结点依次经过的结点形成树的一条路径，最长路径的长度为树的深度

二、
> 输入一棵二叉树的根结点，判断该树是不是平衡二叉树。如果某二叉树中任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
## 题一思路
1. 如果一棵树只有一个结点，它的深度为1
2. 如果根结点只有左子树没有右子树，那么树的深度应该是左子树深度+1
3. 如果根结点只有右子树没有左子树，那么树的深度应该是右子树深度+1
4. 如果根结点既有左子树又有右子树，嘛呢树的深度应该树左、右子树深度较大值+1

## 题二思路一
1. 按照题目一，判断每个结点的左右子树深度相差不超过1
## 题二思路二
1. 利用后序遍历遍历每一个结点
2. 遍历结点时记录深度

## 题一参考代码
```C++
int TreeDepth(BinaryTreeNode* pRoot)
{
    if (pRoot == NULL)
        return 0;
    int left = TreeDepth(pRoot->left);
    int right = TreeDepth(pRoot->right);
    return (left > right) ? left + 1 : right + 1;
}
```
## 题二参考代码
```C++
bool IsBalanced(BinaryTreeNode* pRoot)
{
    if (pRoot == NULL)
        return true;
    int left = TreeDepth(pRoot->left);
    int right = TreeDepth(pRoot->right);
    int dif = left - right;
    if (dif > 1 || dif < -1)
        return false;
    return IsBalanced(pRoot->left) && IsBalanced(pRoot->right);
}
```

```C++
bool IsBalanced(BinaryTreeNode* pRoot)
{
    int depth = 0;
    return IsBalanced(pRoot, &depth);
}

bool IsBalanced(BinaryTreeNode* pRoot, int* pDepth)
{
    if (pRoot == NULL)
    {
        *pDepth = 0;
        return true;
    }
    int left, right;
    if (IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right))
    {
        int dif = left - right;
        if (dif <= 1 && dif >= -1)
        {
            *pDepth = 1 + (left > right) ? left : right;
            return true;
        }
    }
    return false;
}
```