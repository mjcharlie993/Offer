# 23 从上往下打印二叉树
## 题目
> 从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印

## 分析
每次打印一个结点的时候，如果该结点有子节点，则把该结点的子结点放到一个队列的末尾，接下来到队列的头部取出最早进入队列的结点，重复前面的打印操作，直到队列中所有的结点都被打印出来为止。

## 参考代码
```C++
void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot)
{
    if (!pTreeRoot)
        return;
    std::deque<BinaryTreeNode*> dequeTreeNode;
    dequeTreeNode.push_back(pTreeRoot);
    while (dequeTreeNode.empty())
    {
        BinaryTreeNode* pNode = dequeTreeNode.front();
        dequeTreeNode.pop_front();
        printf("%d ", pNode->nValue);
        if (pNode->m_pLeft)
            dequeTreeNode.push_back(pNode->m_pLeft);
        if (pNode->m_pRight)
            dequeTreeNode.push_back(pNode->m_pRight);
    }
}
```