# 65 滑动窗口的最大值
## 题目
> 给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。

## 分析
1. 蛮力算法：遍历每个窗口中最大值，时间复杂度O(nk)
2. 利用队列
    1. 把可能是滑动窗口中最大值的数值存入一个两端开口队列
    2. 如果当前元素比上一次元素大，那么把队列中元素弹出，把该元素放入队列
    3. 如果当前元素比上一次元素小，那么把该元素放入队列
    4. 每次放入队列的是元素的索引值，用i-size来判断元素是否在窗口内
3. index是一个双端队列，用来保存可能是滑动窗口的最大值的数字的下标。
4. 存放一个数字的下标之前，首先判断队列里已有数字是否小于待存入数字
5. 如果小于，那么依次从队尾删除，同时如果队头数字滑出，应该在队列中删除。

## 参考代码
```C++
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> maxInWindows;
    if (num.size() >= size && size >= 1)
    {
        deque<int> index;
        for (unsigned int i = 0; i < size; ++i)
        {
            while (!index.empty() && num[i] >= num[index.back()])
                index.pop_back();
            index.push_back(i);
        }
        for (unsigned int i = size; i < num.size(); ++i)
        {
            maxInWindows.push_back(num[index.front()]);
            while (!index.empty() && num[i] >= num[index.back()])
                index.pop_back();
            if (!index.empty() && index.front() <= (int)(i - size))
                index.pop_front();
            index.push_back(i);
        }
        maxInWindows.push_back(num[index.front()]);
    }
    return maxInWindows;
}
```