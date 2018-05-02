# 61 按之字形顺序打印二叉树
## 题目
> 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
## 思路
1. 需要两个栈
2. 打印某一行结点时，把下一层的子结点保存到相应的栈里，如果当前打印奇数层，则先保存左子结点再保存右子结点到第一个栈中。
3. 如果当前打印偶数层，则先保存右子结点再保存左子结点到第二个栈里

## 参考代码
```C++
void Print(BinaryTreeNode* pRoot)
{
    if (pRoot == NULL)
        return;
    std::stack<BinaryTreeNode*> levels[2];
    int current = 0;
    int next = 1;
    levels[current].push(pRoot);
    while (!levels[0].empty() || !levels[1].empty())
    {
        BinaryTreeNode* pNode = levels[current].top();
        levels[current].pop();
        printf("%d ", pNode->m_nValue);
        if (current == 0)
        {
            if (pNode->m_pLeft != NULL)
                levels[next].push(pNode->m_pLeft);
            if (pNode->m_pRight != NULL)
                levels[next].push(pNode->m_pRight);
        }
        else
        {
            if (pNode->m_pRight != NULL)
                levels[next].push(pNode->m_pRight);
            if (pNode->m_pLeft != NULL)
                levels[next].push(pNode->m_pLeft);
        }
        if (levels[current].empty())
        {
            printf("\n");
            current = 1 - current;
            next = 1 - next;
        }
    }
}
```