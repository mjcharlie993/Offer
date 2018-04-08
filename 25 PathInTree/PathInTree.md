# 25 二叉树中和为某一值的路径
## 题目
> 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶结点所经过的结点形成一条路径。

## 方法
* 利用先序遍历将当前结点值加入到路径中，并累加该结点的值
* 如果该结点的累加值刚好等于输入的整数并且该结点为叶结点，那么就打印该路径
* 如果当前结点不是叶结点，则继续访问它的子结点，当前结点访问结束后，递归函数会自动返回该结点的父节点
* 在结点遍历结束后删除路径上的结点值。确保返回父结点时的路径刚好是从根结点到父结点的路径

## 参考代码
```C++
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
```