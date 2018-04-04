# 包含min函数的栈
## 题目
> 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)

## 思路
1. 利用一个辅助栈来维护最小元素，如果压入元素小于该辅助栈栈顶元素，则在辅助栈中压入该元素，如果压入元素大于辅助栈栈顶元素，则继续压入辅助栈的栈顶元素
2. 弹出时将两个stack的栈顶元素都弹出
3. 任一时刻辅助栈的栈顶元素都是该stack的最小元素

## 参考代码
```C++
template <typename T> 
void StackWithMin<T>::push(const T& value)
{
    m_data.push(value);
    if (m_min.size() == 0 || m_min.top() > value)
        m_min.push(value);
    else
        m_min.push(m_min.top());
}

template <typename T>
void StackWithMin<T>::pop()
{
    assert(m_data.size() > 0 && m_min.size() > 0);
    m_data.pop();
    m_min.pop();
}

template <typename T>
const T& StackWithMin<T>::min() const
{
    assert(m_data.size() > 0 && m_min.size() > 0);
    return m_min.top();
}
```