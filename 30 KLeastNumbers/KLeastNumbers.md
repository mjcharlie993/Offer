# 30 最小的k个数
## 题目
> 输入n个整数，找出其中最小的k个数。
## 思路1
*  利用快排中找中位数的方法找到第k个索引，该索引之前的k个数就是最小的k个数。
* 复杂度O(n)
* 需要修改输入数组
* 不适合海量数据，(即n很大，k很小)
## 思路2
* 利用海量数据处理中的最大堆来处理最小的k个数
* 复杂度O(nlogk)
* 不需要修改输入数组
* 适合海量数据

## 参考代码
* Partition
```C++
// Partition
// O(n)
// 需要修改给定数组
void GetLeastNumbers(int* input, int n, int* output, int k)
{
    if (input == NULL || n <= 0 || output == NULL || k <= 0 || k > n)
        return;
    int start = 0;
    int end = n-1;
    int index = Partition(input, n, start, end);
    while (index != k-1)
    {
        if (index > k-1)
        {
            end = index-1;
            index = Partition(input, n, start, end);
        }
        else
        {
            start = index+1;
            index = Partition(input, n, start, end);
        }
    }
    for (int i = 0; i < k; ++i)
        output[i] = input[i];
}

int Partition(int data[], int length, int start, int end)
{
    if (data == NULL || length <= 0 || start < 0 || end >= length)
        throw new std::exception("Invalid Parameters");
    int index = RandomInRange(start, end);
    Swap(&data[index], &data[end]);
    int small = start - 1;
    for (index = start; index < length; ++index)
    {
        if (data[index] < data[end])
        {
            ++small;
            if (small != index)
                Swap(&data[small], &data[index]);
        }
    }
    ++small;
    Swap(&data[small], &data[end]);
    return small;
}

int RandomInRange(int start, int end)
{
    srand(time(NULL));
    return start + rand() % (end-start+1);
}

void Swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

```
* 最大堆
```C++
// 最大堆
// O(nlogk)
// multiset
typedef multiset<int, greater<int>> intSet;
typedef multiset<int, greater<int>>::iterator setIterator;
void GetLeastNumbers(const vector<int>& data, intSet& leastNumbers, int k)
{
    leastNumbers.clear();
    if (k < 1 || data.size() < k)
        return;
    vector<int>::const_iterator iter = data.begin();
    for (; iter != data.end(); ++iter)
    {
        if (leastNumbers.size() < k)
            leastNumbers.insert(*iter);
        else
        {
            setIterator iterGreatest = leastNumbers.begin();
            if (*iter < *(leastNumbers.begin()))
            {
                leastNumbers.erase(leastNumbers.begin());
                leastNumbers.insert(*iter);
            }
        }
    }
}

```