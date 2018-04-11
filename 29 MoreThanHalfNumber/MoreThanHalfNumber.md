# 29 数组中出现次数超过一半的数字
## 题目
> 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字

## 思路
* 数组中有一个数字出现的次数超过了数组长度的一半，那么排序后位于数组中间的数字一定就是那么出现次数超过数组长度一半的数字。即长度为n的数组中第n/2大的数字

## 解法1：基于partition函数的O(n)算法
* 利用快速排序算法定位到索引为n/2的数

## 参考代码
```C++
int MoreThanHalfNum(int* numbers, int length)
{
    if (CheckInvalidArray(numbers, length))
        return 0;
    int middle = length >> 1;
    int start = 0;
    int end = length - 1;
    int index = Partition(numbers, length, start, end);
    while (index != middle)
    {
        if (index > middle)
        {
            end = index - 1;
            index = Partition(numbers, length, start, end);
        }   
        else
        {
            start = index + 1;
            index = Partition(numbers, length, start, end);
        }
    }
    int result = numbers[middle];
    if (!CheckMoreThanHalf(numbers, length, result))
        result = 0;
    return result;
}

bool g_bInputInvalid = false;
bool CheckInvalidArray(int* numbers, int length)
{
    g_bInputInvalid = false;
    if (numbers == NULL || length <= 0)
        g_bInputInvalid = true;
    return g_bInputInvalid;
}

bool CheckMoreThanHalf(int* numbers, int length, int number)
{
    int times = 0;
    for (int i = 0; i < length; ++i)
    {
        if (numbers[i] == number)
            times++;
    }
    bool isMoreThanHalf = true;
    if (times*2 <= length)
    {
        g_bInputInvalid = true;
        isMoreThanHalf = false;
    }
    return isMoreThanHalf;
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
                Swap(&data[index], &data[small]);
        }
    }
    ++small;
    Swap(&data[small], &data[end]);
    return small;
}

void Swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int RandomInRange(int start, int end)
{
    srand(time(NULL));
    return start + rand() % (end - start + 1);
}
```

## 解法2：根据数组特点找出O(n)的算法
* 出现次数超过数组长度的一半，也就是说它出现的次数比其他数字出现次数的和还要多。
## 思路
1. 遍历数组时保存两个值：一个是数组中的一个数字，一个是次数。
2. 当遍历下一个数字时，如果数字相同，则次数+1，否则-1。如果次数为0，我们需要保存下一个数字并把次数设置为为1。
3. 所以我们要找的数是最后一次把次数设置为1时对应的数字。
## 参考代码
```C++
int MoreThanHalfNum(int* numbers, int length)
{
    if (CheckInvalidArray(numbers, length))
        return 0;
    int result = numbers[0];
    int times = 1;
    for (int i = 1; i < length; ++i)
    {
        if (times == 0)
        {
            result = numbers[i];
            times = 1;
        }
        else if (numbers[i] == result)
            times++;
        else
            times--;
    }
    if (!CheckMoreThanHalf(numbers, length, result))
        result = 0;
    return result;
}
```