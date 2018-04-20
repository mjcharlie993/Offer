# 41 和为s的两个数
## 题目
> 输入一个递增排序的数组和一个数字s，在数组中查找两个数。使得他们的和正好是s，如果由多对数字的和为s输入任意一对即可

## 思路
1. 有序数组可以使用二分查找
2. 如果首末两数和小于s，则说明首元素较小，这时左指针右移，如果首末两数和大于s，则说明末元素较大，右指针左移

## 参考代码
```C++
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
```