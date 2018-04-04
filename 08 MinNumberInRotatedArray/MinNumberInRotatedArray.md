# 08 旋转数组的最小数字
## 题目
> 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组，输出旋转数组的最小元素。例如数组{3，4，5，1，2}为{1，2，3，4，5}的一个旋转，该数组的最小值为1。
## 思路
1. 旋转数组是将一个递增数组分成两个部分，每个部分都是递增数组，分界线为该数组最大值（左数组尾元素）和最小值（右数组头元素）。
2. 利用二分查找法，找出两个数组的边界，也就找到了最小元素。
3. 考虑数组中元素相同的情况（利用顺序查找）。
## 参考代码
```C++
int Min(int* numbers, int length)
{
    if (numbers == NULL || length <= 0)
        throw new std::exception("Invalid parameters");
    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;
    while (numbers[index1] >= numbers[index2])
    {
        if (index1 - index2 == 1)
        {
            indexMid = index2;
            break;
        }
        indexMid = (index1 + index2) / 2;
        if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
            return MinInOrder(numbers, index1, index2);
        if (numbers[indexMid] >= numbers[index1])
            index1 = indexMid;
        else if (numbers[indexMid] <= numbers[index2])
            index2 = indexMid;
    }
    return numbers[indexMid];
}

int MinInOrder(int* numbers, int index1, int index2)
{
    int result = numbers[index1];
    for (int i = index + 1; i <= index2; ++i)
    {
        if (result > numbers[i]) 
            result = numbers[i];
    }
    return result;
}

```