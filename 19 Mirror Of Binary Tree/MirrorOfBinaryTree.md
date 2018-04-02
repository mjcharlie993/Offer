# 19 二叉树的镜像
## 题目
> 请完成一个函数，输入一个二叉树，该函数输出它的镜像
## 思路
* 我们先前序遍历这棵树的每个结点
* 如果遍历到的结点有子结点，就交换它的两个子结点
* 当交换完所有非叶子结点的左右子节点后，就得到树的镜像
## 参考代码
* 递归
```C++
void MirrorRecursively(BinaryTreeNode* pNode)
{
    if (pNode == NULL)
        return;
    if (pNode->left == NULL && pNode->right == NULL)
        return;
    BinaryTreeNode* pTemp = pNode->left;
    pNode->left = pNode->right;
    pNode->right = pTemp;
    if (pNode->left)
        MirrorRecursively(pNode->left);
    if (pNode->right)
        MirrorRecursively(pNode->right);
}
```
* 迭代
```C++
void MirrorIteratively(BinaryTreeNode* pRoot)
{
    if (pRoot == NULL)
        return;
    stack<BinaryTreeNode*> s;
    s.push(pRoot);
    while (!s.empty())
    {
        BinaryTreeNode* pNode = s.top();
        s.pop();
        BinaryTreeNode* pTemp = pNode->left;
        pNode->left = pNode->right;
        pNode->right = pTemp;
        if (pNode->left)
            s.push(pNode->left);
        if (pNode->right)
            s.push(pNode->right);
    }
}
```