bool VerifySquenceOfBST(int sequence[], int length)
{
    if (sequence == NULL || length <= 0)
        return false;
    int root = sequence[length - 1];

    int i = 0;
    for (; i < length - 1; ++i)
    {
        if (sequence[i] > root)
            break;
    }
    int j = i;
    for (; j < length - 1; ++j)
    {
        if (sequence[j] < root)
            return false;
    }
    bool left = true;
    if (i > 0)
        left = VerifySquenceOfBST(sequence, i);
    bool right = true;
    if (i < length - 1)
        right = VerifySquenceOfBST(sequence + i, length - i - 1);
    return (left && right);
}