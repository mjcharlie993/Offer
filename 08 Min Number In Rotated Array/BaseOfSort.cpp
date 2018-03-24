// QuickSort
int Partition(int data[], int length, int start, int end)
{
    if (data == NULL || length <= 0 || start < 0 || end >= length)
        throw new std::exception("Invalid Parameters");
    int index = RandomInRange(start, end);
    Swap(&data[index], &data[end]);
    int small = start - 1;
    for (index = start; index < end; ++index)
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

void QuickSort(int data[], int length, int start, int end)
{
    if (start == end)
        return;
    int index = Partition(data, length, start, end);
    if (index > start)
        QuickSort(data, length, start, index - 1);
    if (index < end)
        QuickSort(data, length, index + 1, end);
}


// Sort Age
void SortAge(int ages[], int length)
{
    if (ages == NULL || length <= 0)
        return;
    const int oldestAge = 99;
    int timesOfAge[oldestAge + 1];
    for (int i = 0; i <= oldestAge; ++i)
        timesOfAge[i] = 0;
    for (int i = 0; i < length; ++i)
    {
        int age = ages[i];
        if (age < 0 || age > oldestAge)
            throw new std::exception("age out of range.");
        ++timesOfAge[age];
    }
    int index = 0;
    for (int i = 0; i <= oldestAge; ++i)
    {
        for (int j = 0; j < timesOfAge[i]; ++j)
        {
            ages[index] = i;
            ++index;
        }
    }
}

