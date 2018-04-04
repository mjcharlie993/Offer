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

void MirrorIteratively(BinaryTreeNode* pRoot)
{
    if (pRoot == NULL)
        return;
    stack<BinaryTreeNode*> s;
    s.push(pRoot);
    while (!s.empty())
    {
        BinaryTreeNode* pNode = s.top();
        t.pop();
        BinaryTreeNode* pTemp = pNode->left;
        pNode->left = pNode->right;
        pNode->right = pTemp;
        if (pNode->left)
            s.push(pNode->left);
        if (pNode->right)
            s.push(pNode->right);
    }
}