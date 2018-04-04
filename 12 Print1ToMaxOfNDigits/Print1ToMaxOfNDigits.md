# 12 打印1到最大的n位数
## 题目
> 输入数字n，按顺序打印从1最大的n位十进制数。比如输入3，则打印出1、2、3一直到最大的3位数即999

## 思路
* 迭代
1. 利用字符串数组来保存大数。
2. 申请容量为n+1的字符数组，第n位为'\0'，其他位为'0'
3. 逐位模拟数字相加，直到最高位产生进位。
4. 输出去除字符数组0数字前缀的数字。

* 递归
1. n位数的一位都是0-9的循环组合。也就是n位数的全排列
2. 递归求出全排列即可
## 参考代码
* 迭代
```C++
void Print1ToMaxOfNDigits(int n)
{
    if (n <= 0)
        return;
    char* number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';
    while (!Increment(number))
        PrintNumber(number);
    delete[] number;
}

bool Increment(char* number)
{
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLength = strlen(number);
    for (int i = nLength - 1; i >= 0; i--)
    {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength - 1)
            nSum++;
        if (nSum >= 10)
        {
            if (i == 0)
                isOverflow = true;
            else
            {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        }
        else
        {
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverflow;
}

void PrintNumber(char* number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);
    for (int i = 0; i < nLength; ++i)
    {
        if (isBeginning0 && number[i] != '0')
            isBeginning0 = false;
        if (!isBeginning0)
            printf("%s", number[i]);
    }
    printf("\t");
}
```
* 递归
```C++
void Print1ToMaxNDigits(int n)
{
    if (n <= 0)
        return;
    char* number = new char[n+1];
    number[n] = '\0';
    for (int i = 0; i < 10; ++i)
    {
        number[0] = i + '0';
        Print1ToMaxNDigitsRecursively(number, n, 0);
    }
    delete[] number;
}

void Print1ToMaxNDigitsRecursively(char* number, int length, int index)
{
    if (index == length - 1)
    {
        PrintNumber(number);
        return;
    }
    for (int i = 0; i < length; ++i)
    {
        number[index+1] = i + '0';
        Print1ToMaxNDigitsRecursively(number, length, index+1);
    }
}
```