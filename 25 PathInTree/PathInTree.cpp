void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
    if (pRoot == NULL)
        return;
    std::vector<int> path;
    int currentSum = 0;
    FindPath(pRoot, expectedSum, path, currentSum);
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int currentSum)
{
    currentSum += pRoot->val;
    path.push_back(pRoot->val);
    bool isLeaf = pRoot->left == NULL && pRoot->right == NULL;
    if (currentSum == expectedSum && isLeaf)
    {
        printf("A path is found: ");
        std::vector<int>::iterator iter = path.begin();
        for (; iter != path.end(); ++iter)
            printf("%d\t", *iter);
        printf("\n");
    }
    if (pRoot->left != NULL)
        FindPath(pRoot->left, expectedSum, path, currentSum);
    if (pRoot->right != NULL)
        FindPath(pRoot->right, expectedSum, path, currentSum);
    path.pop_back();
}