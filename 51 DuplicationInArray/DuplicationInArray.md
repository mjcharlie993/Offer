# 51 数组中过重复的数字
## 题目
> 在一个长度为n的数组中的所有数字都是在0到n-1范围内。数组中某些数字时重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
## 思路
1. 排序
2. 哈希表
3. 重拍数组
    1. 排序后数字i应该出现在下标为i的位置
    2. 扫描到下标为i的数字时，比较这个数字m是不是等于i
    3. 如果是那么接着扫描下一个数字，如果不是那么和第m个位置的数字比较，如果相等那么就找到了重复数字，如果不等那么就交换两个数字，把m放到属于它的位置
## 参考代码
```C++
bool duplicate(int numbers[], int length, int* duplication)
{
    if (numbers == NULL || length <= 0)
        return false;
    for (int i = 0; i < length, ++i)
    {
        if (numbers[i] < 0 || numbers[i] > length - 1)
            return false;
    }
    for (int i = 0; i < length; ++i)
    {
        while (numbers[i] != i)
        {
            if (numbers[i] == numbers[numbers[i]])
            {
                *duplication =  numbers[i];
                return true;
            }
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
    return false;
}
```