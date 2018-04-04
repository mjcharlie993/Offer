bool g_InvalidInput = false;
int FindGreatestSumOfSubArray(int* pData, int nLength)
{
    if (pData == NULL || nLength <= 0)
    {
        g_InvalidInput = true;
        return 0;
    }
    g_InvalidInput = false;
    int nCurSum = 0;
    int nGreatestSum = 0x80000000;
    for (int i = 0; i < nLength; ++i)
    {
        if (nCurSum <= 0)
            nCurSum = pData[i];
        else
            nCurSum += pData[i];
        if (nCurSum > nGreatestSum)
            nGreatestSum = nCurSum;
    }
    return nGreatestSum;
}

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