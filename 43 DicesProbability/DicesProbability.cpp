int g_maxValue = 6;
void PrintProbability(int number)
{
    if (number < 1)
        return;
    int maxSum = number * g_maxValue;
    int* pProbabilities = new int[maxSum - number + 1];
    for (int i = number; i <= maxSum; ++i)
        pProbabilities[i - number] = 0;
    Probability(number, pProbabilities);
    int total = pow((double)g_maxValue, number);
    for (int i = number; i <= maxSum; ++i)
    {
        double ratio = (double)pProbabilities[i - number] / total;
        printf("%d: %e\n", i, ratio);
    }
    delete[] pProbabilities;
}

void Probability(int number, int* pProbabilities)
{
    for (int i = 1; i <= g_maxValue; ++i)
        Probability(number, number, i, pProbabilities);
}

void Probability(int original, int current, int sum, int* pProbabilities)
{
    if (current == 1)
    {
        pProbabilities[sum - original]++;
    }
    else
    {
        for (int i = 1; i <= g_maxValue; ++i)
        {
            Probability(original, current - 1, i + sum, pProbabilities);
        }
    }
}

void PrintProbability(int number)
{
    if (number < 1)
    {
        return ;
    }
    int *pProbabilities[2];
    pProbabilities[0] = new int[g_maxValue * number + 1];
    pProbabilities[1] = new int[g_maxValue * number + 1];
    for (int i = 0; i < g_maxValue; ++i)
    {
        pProbabilities[0][i] = 0;
        pProbabilities[1][i] = 0;
    }

    int flag = 0;
    for (int i = 1; i <= g_maxValue; ++i)
    {
        pProbabilities[flag][i] = 1;
    }

    for (int k = 2; k <= number; ++k)
    {
        for (int i = 0; i < k; ++i)
        {
            pProbabilities[1 - flag][i] = 0;
        }

        for (int i = k; i <= g_maxValue * k; ++i)
        {
            pProbabilities[1 - flag][i] = 0;
            for (int j = 1; j <= i && j <= g_maxValue; ++j)
            {
                pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
            }
        }
        flag = 1 - flag;
    }
    double total = pow( (double)g_maxValue, number);
    for (int i = number; i <= g_maxValue * number; ++i)
    {
        double ratio = (double)pProbabilities[flag][i] / total;
        printf("%d: %e\n", i, ratio);
    }
    delete[] pProbabilities[0];
    delete[] pProbabilities[1];
}


// dp
class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        // Write your code here
        vector<pair<int, double>> res;
        if (n < 1)
            return res;
        vector<vector<double>> dp(n+1, vector<double>(6*n+1, 0));
        for (int i = 1; i < n+1; ++i)
        {
            for (int j = 1; j < 6*i+1; ++j)
            {
			    if (i == 1 || i == j || 6 * i == j)
			    {
				    dp[i][j] = 1;
			    }
			    else
			    {
				    for (int k = 1; k < 7; ++k)
				    {
					    if (i - 1 <= j - k)
						    dp[i][j] += dp[i - 1][j - k];
				    }
			    }
            }
        }
        double total = pow(6.0, n);
        for (int i = n; i < 6 * n + 1; ++i)
        {
            long double ratio = 0;
            if (dp[n][i] != 0)
                ratio = (long double)dp[n][i] / total;
            res.push_back(make_pair(i, ratio));
        }
        return res;
    }
};