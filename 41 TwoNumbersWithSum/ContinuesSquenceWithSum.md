# 41 和为s的连续正数序列
## 题目
> 输入一个正数s，打印出所有和为s的连续正数序列(至少含有2个数)
## 思路
1. 考虑两个数small和big分别表示序列最大值和最小值。small初始化为1， big初始化为2，如果small到big序列和大于s，我们从序列中取消较小的值，也就是增大small，反之增加big
2. 直到small增大到(1+s)/2为止

## 参考代码
```C++
void FindContinuousSequence(int num)
{
    if (sum < 3)
        return;
    int small = 1;
    int big = 2;
    int middle = (1 + sum) / 2;
    int curSum = small + big;
    while (small < middle)
    {
        if (curSum == sum)
            PrintContinuousSequence(small, big);
        while (curSum > sum && small < middle)
        {
            curSum -= small;
            small++;
            if (curSum == sum)
                PrintContinuousSequence(small, big);
        }
        big++;
        curSum += big;
    }
}

void PrintContinuousSequence(int small, int big)
{
    for (int i = small; i <= big; ++i)
        printf("%d ", i);
    printf("\n");
}
```