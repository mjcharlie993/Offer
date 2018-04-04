# 31 连续子数组的最大和
## 题目
> 输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)

## 分析
1. 根据数组的规律进行计算。

如果子数组最大和为负数，则令其归0。从数组中下一个数开始累计。
遇到负数时：暂存当前子数组最大和，直到后续子数组最大和大于该值时更新。

2. 利用动态规划暂存每一步的计算结果。

## 参考代码
* 常规方法
```C++
int FindGreatestSumOfSubArray(int* pData, int nLength)
{
    if (pData == NULL || nLength <= 0)
        return 0;
    int nCurSum = 0;
    int nGreatestSum = INT_MIN;
    for (int i = 0; i < nLength; ++i)
    {
        if (nCurSum <= 0)
            nCurSum = pData[i];
        else
            nCurSum += pData[i];
        if (nGreatestSum < nCurSum)
            nGreatestSum = nCurSum;
    }
    return nGreatestSum;
}
```
* 动态规划
```C++
// dp
int FindGreatestSumOfSubArray(int* pData, int nLength)
{
    if (pData == NULL || nLength <= 0)
        return 0;
    int dp[nLength];
    dp[0] = pData[0];
    int maxSum = INT_MIN;
    for (int i = 1; i < nLength; ++i)
    {
        if (dp[i-1] <= 0)
            dp[i] = pData[i];
        else
            dp[i] = dp[i-1] + pData[i];
        if (maxSum < dp[i])
            maxSum = dp[i];
    }
    return maxSum;
}
```