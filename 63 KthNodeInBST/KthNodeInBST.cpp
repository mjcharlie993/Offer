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