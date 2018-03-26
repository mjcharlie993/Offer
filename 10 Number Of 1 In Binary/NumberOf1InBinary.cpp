// Inefficient
int NumberOf1(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while (flag)
    {
        if (n & 1)
            count++;
        flag = flag << 1;
    }
    return count;
}

// Efficient
int NumberOf1(int n)
{
    int count = 0;
    while (n)
    {
        ++count;
        n = (n - 1) & n;
    }
    return count;
}