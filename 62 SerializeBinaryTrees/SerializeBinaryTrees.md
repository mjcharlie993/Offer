# 62 序列化二叉树
## 题目
> 请实现两个函数，分别用来序列化喝热反序列化二叉树
## 思路
1. 根据前序遍历来序列化二叉树，遇到NULL指针时，变成'$'替代，结点之间用','隔开

## 参考代码
```C++
void Serialize(BinaryTreeNode* pRoot, ostream& stream)
{
    if (pRoot == NULL)
    {
        stream << '$,';
        return;
    }
    stream << pRoot->m_nValue << ',';
    Serialize(pRoot->m_pLeft, stream);
    Serialize(pRoot->m_pRight, stream); 
}

void Deserialize(BinaryTreeNode** pRoot, istream& stream)
{
    int number;
    if (ReadStream(stream, &number))
    {
        *pRoot = new BinaryTreeNode();
        (*pRoot)->m_nValue = number;
        (*pRoot)->m_pLeft = NULL;
        (*pRoot)->m_pRight = NULL;
        Deserialize(&((*pRoot)->m_pLeft), stream);
        Deserialize(&((*pRoot)->m_pRight), stream);
    }
}
// ReadStream:每次从流中读出一个数字或一个字符'$'。当从流中读出一个数字时返回true，否则返回false
```