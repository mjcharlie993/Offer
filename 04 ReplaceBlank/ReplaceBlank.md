# 04 替换空格
## 题目
> 请实现一个函数，把字符串中的每个空格替换成%20。例如输入“We are happy.”，则输出“We%20are%20happy.”。
## 时间复杂度为O(n)的算法
* 从后向前赋值字符串
* 先遍历一次字符串找出字符串，统计字符串中字符总数和空格数，计算替换后字符串总长度
* 从字符串后面开始复制和替换，准备两个指针分别指向原始字符串末尾和替换之后字符串末尾，逐字符扫描并替换
## 注意
* 首先对字符串进行参数判断
* 确认替换后的字符串长度没有超过原字符串的总容量
* 循环边界条件
## 参考代码
```C++
void ReplaceBlank(char string[], int length)
{
    if (string == NULL || length <= 0)
        return;
    
    int originalLength = 0, numberOfBlank = 0;
    int i = 0;
    while (string[i] != '\0')
    {
        ++originalLength;
        if (string[i] == ' ')
            ++numberOfBlank;
        ++i;
    }

    int newLength = originalLength + numberOfBlank * 2;
    if (newLength > length)
        return;
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if (string[indexOfOriginal] == ' ')
        {
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        }
        else
        {
            string[indexOfNew--] = string[indexOfOriginal];
        }
        --indexOfOriginal;
    }
}
```
