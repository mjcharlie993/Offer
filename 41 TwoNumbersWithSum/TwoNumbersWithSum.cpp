bool FindNumbersWithSum(int data[], int length, int sum, int* num1, int* num2)
{
    bool found = false;
    if (data == NULL || length < 1 || num1 == NULL || num2 == NULL)
        return found;
    int ahead = length - 1;
    int behind = 0;
    while (ahead > behind)
    {
        long long curSum =  data[ahead] + data[behind];
        if (curSum == sum)
        {
            *num1 = data[ahead];
            *num2 = data[behind];
            found = true;
            break;
        }
        else if (curSum > sum)
            ahead--;
        else
            behind++
    }
    return found;
}