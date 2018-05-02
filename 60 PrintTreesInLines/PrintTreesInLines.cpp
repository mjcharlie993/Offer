void Print(BinaryTreeNode* pRoot)
{
    if (pRoot == NULL)
        return;
    std::queue<BinaryTreeNode*> nodes;
    nodes.push(pRoot);
    int nextLevel = 0;
    int toBePrinted = 1;
    while (!nodes.empty())
    {
        BinaryTreeNode* pNode = nodes.front();
        printf("%d ", pNode->m_nValue);
        if (pNode->m_pLeft != NULL)
        {
            nodes.push(pNode->m_pLeft);
            ++nextLevel;
        }
        if (pNode->m_pRight != NULL)
        {
            nodes.push(pNode->m_pRight);
            ++nextLevel;
        }
        nodes.pop();
        --toBePrinted;
        if (toBePrinted == 0)
        {
            printf("\n");
            toBePrinted = nextLevel;
            nextLevel = 0;
        }
    }
}