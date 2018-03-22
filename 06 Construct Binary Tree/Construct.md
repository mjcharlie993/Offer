# 06 重建二叉树
## 题目
> 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果都不包含重复的数字。例如输入前序遍历序列{1，2，4，7，3，5，6，8}和中序遍历序列{4，7，2，1，5，3，8，6}，重建二叉树并输出它的头结点。
## Tips
 1、前序遍历中第一个数字总是树的根节点值。

 2、中序遍历中，根结点的值在序列中间，左子树的结点的值位于根节点的左边，右子树的结点的值位于根结点的右边。

## 思路
* 通过前序遍历找出根节点的值（Tip 1）
* 在中序遍历中定位根节点并通过根节点位置将前序遍历序列分割成前后两个部分（Tip 2）
* 通过上述方法递归构造左右子树即可

## 参考代码
```C++
BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if (preorder == NULL || inorder == NULL || length <= 0)
        return NULL;
    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
    // find root value in preorder.
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;

    if (startPreorder == endPreorder)
    {
        if (startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
            throw std::exception("Invalid input.");
    }

    // find root node in inorder.
    int* rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue)
        ++rootInorder;
    if (rootInorder == endInorder && *rootInorder != rootValue)
        throw std::exception("Invalid input.");
    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if (leftLength > 0)
    {
        // construct left subtree.
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
    }
    if (leftLength < endPreorder - startPreorder)
    {
        // construct right subtree.
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
    }
    return root;
}
```
