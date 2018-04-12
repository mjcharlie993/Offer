// Partition
// O(n)
// 需要修改给定数组
void GetLeastNumbers(int* input, int n, int* output, int k)
{
    if (input == NULL || n <= 0 || output == NULL || k <= 0 || k > n)
        return;
    int start = 0;
    int end = n-1;
    int index = Partition(input, n, start, end);
    while (index != k-1)
    {
        if (index > k-1)
        {
            end = index-1;
            index = Partition(input, n, start, end);
        }
        else
        {
            start = index+1;
            index = Partition(input, n, start, end);
        }
    }
    for (int i = 0; i < k; ++i)
        output[i] = input[i];
}

int Partition(int data[], int length, int start, int end)
{
    if (data == NULL || length <= 0 || start < 0 || end >= length)
        throw new std::exception("Invalid Parameters");
    int index = RandomInRange(start, end);
    Swap(&data[index], &data[end]);
    int small = start - 1;
    for (index = start; index < length; ++index)
    {
        if (data[index] < data[end])
        {
            ++small;
            if (small != index)
                Swap(&data[small], &data[index]);
        }
    }
    ++small;
    Swap(&data[small], &data[end]);
    return small;
}

int RandomInRange(int start, int end)
{
    srand(time(NULL));
    return start + rand() % (end-start+1);
}

void Swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


// 最大堆
// O(nlogk)
// multiset
typedef multiset<int, greater<int>> intSet;
typedef multiset<int, greater<int>>::iterator setIterator;
void GetLeastNumbers(const vector<int>& data, intSet& leastNumbers, int k)
{
    leastNumbers.clear();
    if (k < 1 || data.size() < k)
        return;
    vector<int>::const_iterator iter = data.begin();
    for (; iter != data.end(); ++iter)
    {
        if (leastNumbers.size() < k)
            leastNumbers.insert(*iter);
        else
        {
            setIterator iterGreatest = leastNumbers.begin();
            if (*iter < *(leastNumbers.begin()))
            {
                leastNumbers.erase(leastNumbers.begin());
                leastNumbers.insert(*iter);
            }
        }
    }
}
