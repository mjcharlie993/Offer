# 22 栈的压入、弹出序列
## 题目
> 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有元素均不相等。

## 规律
如果下一个弹出的元素刚好是栈顶元素，那么直接弹出，如果下一个弹出的元素不在栈顶，我们把压栈序列中还没有入栈的数字压入辅助栈，直到把下一个需要弹出的数字压入栈顶为止，如果所有的元素都压入栈了仍然没有找到下一个弹出的数字，那么该序列不可能是一个弹出序列

## 参考代码
```C++
bool isPopOrder(const int* pPush, const int* pPop, int nLength)
{
    bool bPossible = false;
    if (pPush != NULL && pPop != NULL && nLength > 0)
    {
        const int* pNextPush = pPush;
        const int* pNextPop = pPop;
        std::stack<int> stackData;
        while (pNextPop - pPop < nLength)
        {
            while (stackData.empty() || stackData.top() != *pNextPop)
            {
                if (pNextPush - pPush == nLength)
                    break;
                stackData.push(*pNextPush);
                pNextPush++;
            }

            if (stackData.top() != pNextPop)
                break;
            stackData.pop();
            pNextPop++;
        }
        if (stackData.empty() && pNextPop - pPop == nLength)
            bPossible = true;
    }
    return bPossible;
}
```