# 63 二叉搜索树的第k个结点
## 题目
> 给定一棵二叉搜索树，请找出其中的第k大的结点

## 思路
1. 中序遍历找到第k个结点

## 参考代码
```C++
BinaryTreeNode* KthNode(BinaryTreeNode* pRoot, unsigned int k)
{
    if (pRoot == NULL || k == 0)
        return NULL;
    return KthNodeCore(pRoot, k);
}

BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot, unsigned int k)
{
    BinaryTreeNode* target = NULL;
    if (pRoot->m_pLeft != NULL)
        target = KthNodeCore(pRoot->m_pLeft, k);
    if (target == NULL)
    {
        if (k == 1)
            target = pRoot;
        k--;
    }
    if (target == NULL && pRoot->m_pRight != NULL)
        target = KthNodeCore(pRoot->m_pRight, k);
    return target;
}
```

```C++
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (pRoot == NULL || k == 0)
            return NULL;
        vector<TreeNode*> res;
        dfs(pRoot, res);
        if (k > res.size())
            return NULL;
        return res[k-1];
    }
    void dfs(TreeNode* root, vector<TreeNode*>& res)
    {
        if (root == NULL)
            return;
        dfs(root->left, res);
        res.push_back(root);
        dfs(root->right, res);
    }
};

```