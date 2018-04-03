# 顺时针打印矩阵
## 题目
> 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
## 思路
* 把矩阵看成由若干个顺时针方向的圈组成
* 打印每一圈时判断循环条件
    * 上到下→起始行号<终止行号
    * 右到左→至少两行两列（起始行号<终止行号 && 起始列号<终止列号）
    * 下到上→至少三行两列（起始行号+1 < 终止行号 && 起始列号 < 终止列号）

## 参考代码
```C++
void PrintMatrixClockwisely(int** numbers, int columns, int rows)
{
    if (numbers == NULL || columns <= 0 || rows <= 0)
        return;
    int start = 0;
    while (colums > start * 2 && rows > start * 2)
    {
        PrintMatrixInCircle(numbers, columns, rows, start);
        ++start;
    }
}

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start)
{
    int endX = columns - 1 - start;
    int endY = rows - 1 -start;
    for (int i = 0; i <= endX; ++i)
    {
        int number = numbers[start][i];
        printNumber(number);
    }
    if (start < endY)
    {
        for (int i = start + 1; i <= endY; ++i)
        {
            int number = numbers[i][endX];
            printNumber(number);
        }
    }
    if (start < endX && start < endY)
    {
        for (int i = endX - 1; i >= start; --i)
        {
            int number = numbers[endY][i];
            printNumber(number);
        }
    }
    if (start < endX && start < endY - 1)
    {
        for (int i = endY - 1; i >= start + 1; --i)
        {
            int number = numbers[i][start];
            printNumber(number);
        }
    }
}

```