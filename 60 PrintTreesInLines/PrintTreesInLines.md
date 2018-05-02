# 60 把二叉树打印成多行
## 题目
> 从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层打印到一行。
## 思路
1. 用一个队列来保存将要打印的结点。
2. 为了把二叉树的每一行单独打印到一行里，我们需要两个变量：一个变量表示当前层中没有打印的结点数，另一个变量表示下一层结点的数目。

## 参考代码
```C++
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
```