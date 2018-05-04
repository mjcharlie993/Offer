# 64 数据流中的中位数
## 题目
> 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序后中间两个数的平均值

## 分析
1. 由于数据是从数据流中读出，所以需要一个数据容器来保存从流中读出的数据
2. 选择合适的容器
    1. 未排序的数组，插入O(1),找出O(n)
    2. 排序的数组，插入O(n),找出O(1)
    3. 排序链表，插入O(n),找出O(1)
    4. BST,插入平均O(logn)平均O(n),找出平均O(logn)平均O(n)
    5. AVL,插入O(logn),找出O(1)
    6. 堆，插入O(logn),找出O(1)
3. 一个数组分成两部分，左部分数值都小于右部分数值，那么左部分中最大值和右部分最小值若相同就是中位数，若不同，求平均得到中位数
4. 利用最大堆模拟数组左半部分，最小堆模拟数组右半部分。堆顶元素就是两个数组临界值
5. 为了保证最大堆中数字都小于最小堆，首先先将数字插入最小堆，取最小堆堆顶元素放入最大堆即可。
6. 利用STL中push_heap、pop_heap、vector、less、greater实现最大堆和最小堆

## 参考代码
```C++
template <typename T>
class DynamicArray
{
public:
    void Insert(T num)
    {
        if ((min.size() + max.size()) & 1 == 0)
        {
            if (max.size() > 0 && num < max[0])
            {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<T>());
                num = max[0];
                pop_heap(max.begin(), max.end(), less<T>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<T>());
        }
        else
        {
            if (min.size() > 0 && num > min[0])
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<T>());
                num = min[0];
                pop_heap(min.begin(), min.end(), greater<T>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<T>());
        }

    }
    T GetMedian()
    {
        int size = min.size() + max.size();
        if (size == 0)
            throw exception("No numbers are available");
        T median = 0;
        if ((size & 1) == 1)
            median = min[0];
        else
            median = (min[0] + max[0]) / 2;
        return median;
    }
private:
    vector<T> min;
    vector<T> max;
};
```