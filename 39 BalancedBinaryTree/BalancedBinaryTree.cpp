int TreeDepth(BinaryTreeNode* pRoot)
{
    if (pRoot == NULL)
        return 0;
    int left = TreeDepth(pRoot->left);
    int right = TreeDepth(pRoot->right);
    return (left > right) ? left + 1 : right + 1;
}

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