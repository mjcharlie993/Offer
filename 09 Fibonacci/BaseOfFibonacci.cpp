// Recursive
int AddFrom1toN_Recursive(int n)
{
    return n <= 0 ? 0 : n + AddFrom1toN_Recursive(n - 1);
}

// Iterative
int AddFrom1toN_Iterative(int n)
{
    int result = 0;
    for (int i = 1; i <= n; ++i)
        result += i;
    return result;
}

