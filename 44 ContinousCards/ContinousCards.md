# 44 扑克牌的顺子
## 题目
> 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2~10为数字本身，A为1，J为11，Q为12，K为13，而大小王可以看成任意数字
## 思路
1. 数组排序
2. 统计数组中0的个数
3. 统计排序后数组中相邻数字之间的空缺总数
4. 如果空缺总数小于或等于0的个数，那么数组就是连续的。反之不连续
5. 如果非0数字重复出现，则数组不连续

## 参考代码
```C++
bool IsContinuous(int* numbers, int length)
{
    if (numbers == NULL || length < 1)
        return false;
    qsort(numbers, length, sizeof(int), compare);
    int numberOfZero = 0;
    int numberOfGap = 0;
    for (int i = 0; i < length && numbers[i] == 0; ++i)
        ++numberOfZero;
    int small = numberOfZero;
    int big = small + 1;
    while (big < length)
    {
        if (numbers[small] == numbers[big])
            return false;
        numberOfGap += numbers[big] - numbers[small] - 1;
        small = big;
        ++big;
    }
    return (numberOfGap > numberOfZero) ? false : true;
}

int compare(const void* arg1, const void* arg2)
{
    return *(int*)arg1 - *(int*)arg2;
}
```