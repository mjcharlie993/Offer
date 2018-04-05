# 24 二叉搜索树的后序遍历序列
## 题目
> 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果，如果是则返回true，否则返回false

## 后序遍历
* 在后序遍历得到的序列中，最后一个数字是树的根节点的值。数组中前面的数字可以分为两部分：第一部分是左子树结点的值，它们都比根结点的值小；第二部分是右子树结点的值，它们都比根结点的值大。
* 用该方法递归的判断每个部分的子树结构。

## 参考代码
```C++
bool VerifySquenceOfBST(int sequence[], int length)
{
    if (sequence == NULL || length <= 0)
        return false;
    int root = sequence[length - 1];

    int i = 0;
    for (; i < length - 1; ++i)
    {
        if (sequence[i] > root)
            break;
    }
    int j = i;
    for (; j < length - 1; ++j)
    {
        if (sequence[j] < root)
            return false;
    }
    bool left = true;
    if (i > 0)
        left = VerifySquenceOfBST(sequence, i);
    bool right = true;
    if (i < length - 1)
        right = VerifySquenceOfBST(sequence + i, length - i - 1);
    return (left && right);
}
```
