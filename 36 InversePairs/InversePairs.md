# 36 数组中的逆序对
## 题目
> 在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
## 思路
1. 将数组拆分成长度为2的子数组，确定其中的逆序对后排序。
2. 利用两个指针分别指向子数组的末尾数字，比较如果第一次子数组中元素大于第二个子数组中元素，则逆序对数组等于第二个数组中剩余数字的个数。如果第一个数组中元素小于等于第二个子数组中的元素，不构成逆序对。
3. 每次比较时将较大的元素放入辅助数组中。确保辅助数组中的元素是增序。每放入一个元素，对应的子数组指针前移一位。
---
1. 冒泡排序中交换的次数就是逆序对的个数
---
* 稳定排序的应用
## 参考代码
```C++
int InversePairs(int* data, int length)
{
    if (data == NULL || length <= 0)
        return 0;
    int* copy = new int[length];
    for (int i = 0; i < length; ++i)
        copy[i] = data[i];
    int count = InversePairsCore(data, copy, 0, length - 1);
    delete[] copy;
    return count;
}

int InversePairsCore(int* data, int* copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}
	int length = (end - start) / 2;
	int left = InversePairsCore(copy, data, start, start + length);
	int right = InversePairsCore(copy, data, start + length + 1, end);
	int i = start + length;
	int j = end;
	int indexCopy = end;
	int count = 0;
	while (i >= start && j >= start + length + 1)
	{
		if (data[i] > data[j])
		{
			copy[indexCopy--] = data[i--];
			count += j - start - length;
		}
		else
		{
			copy[indexCopy--] = data[j--];
		}
	}
	for (; i >= start; --i)
		copy[indexCopy--] = data[i];
	for (; j >= start + length + 1; --j)
		copy[indexCopy--] = data[j];
	return left + right + count;
}
```