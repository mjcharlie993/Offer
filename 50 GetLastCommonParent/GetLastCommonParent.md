# 50 树中两个结点的最低公共祖先
## 题目
> 输入两个树结点，求它们的最低公共祖先
## 思路
1. 如果是二叉搜索树
    1. 从树的根结点开始和两个输入的结点进行比较。
    2. 如果当前结点的值比两个结点的值都大，那么最低的共同父节点一定是在当前结点的左子树中
    3. 如果当前结点的值比两个结点的值都小，那么最低的共同父节点一定是在当前结点的右子树中
    4. 这样在树中从上到小找到的第一个在两个输入结点的值之间的结点，就是最低的公共祖先

2. 如果是普通的树，树的结点存在指向父结点的指针
    1. 转换为求两个链表的第一个公共结点
    2. 树中每一个叶结点开始都有一个由指针串起来的链表，这些链表的尾指针都是树的根结点
    3. 那么输入的两个结点的最低公共祖先刚好就是两个两个链表的第一个公共结点
3. 如果是普通的树，树的结点不存在指向父结点的指针
    1. 两个结点的公共祖先，就是两个结点都出现在某个结点的子树中
    2. 从根结点开始遍历一棵树，每遍历到一个结点时，判断两个输入结点是不是在它们的子树中，如果在子树中，则分别遍历它们的所有结点，并判断输入结点是不是在它们的子树中
    3. 从上到下一直找到第一个结点，它自己的子树中同时包含两个输入的结点而它的子结点没有，那么这个结点就是最低公共子树
4. 三中存在遍历多次同一结点，考虑到用辅助内存的情况
    1. 遍历时用一个辅助内存保存路径（从根节点到输入结点）
    2. 链表的最后公共结点就是所求结点

## 参考代码
```C++
bool GetNodePath(TreeNode* pRoot, TreeNode* pNode, list<TreeNode*>& path)
{
    if (pRoot == pNode)
        return true;
    path.push_back(pRoot);
    bool found = false;
    vector<TreeNode*>::iterator i = pRoot->m_vChildren.begin();
    while (!found && i < root->m_vChildren.end())
    {
        found = GetNodePath(*i, pNode, path);
        ++i;
    }
    if (!found)
        path.pop_back();
    return found;
}

TreeNode* GetLastCommonNode(const list<TreeNode*>& path1, const list<TreeNode*>& path2)
{
    list<TreeNode*>::const_iterator iterator1 = path1.begin();
    list<TreeNode*>::const_iterator iterator2 = path2.begin();
    TreeNode* pLast = NULL;
    while (iterator1 != path1.end() && iterator2 != path2.end())
    {
        if (*iterator1 == *iterator2)
            pLast = *iterator1;
        iterator1++;
        iterator2++;
    }
    return pLast;
}

TreeNode* GetLastCommonParent(TreeNode* pRoot, TreeNode* pNode1, TreeNode* pNode2)
{
    if (pRoot == NULL || pNode1 == NULL || pNode2 == NULL)
        return NULL;
    list<TreeNode*> path1;
    GetNodePath(pRoot, pNode1, path1);
    list<TreeNode*> path2;
    GetNodePath(pRoot, pNode2, path2);
    return GetLastCommonNode(path1, path2);
}
```