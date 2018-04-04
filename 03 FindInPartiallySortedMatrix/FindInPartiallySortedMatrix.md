# 03 二维数组中的查找
## 题目
> 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样一个二维数组和一个整数，判断数组中是否含有该整数。
## 思路
* 首先选取数组中右上角的数字。
* 如果该数字等于要查找的数字，查找过程结束；
* 如果该数字大于要查找的数字，剔除这个数字所在的列；
* 如果该数字小于要查找的数字，剔除这个数字所在的行。

## 注意
* 初始数组的条件判断
* 循环时的边界判断
## 参考代码
从数组右上角到左下角遍历
```C++
// from top-right to bottom-left
bool find(int* matrix, int rows, int cols, int number)
{
    bool isFound = false;
    if (matrix != NULL && rows > 0 && cols > 0)
    {
        int row = 0, col = cols - 1;
        while (row < rows && col >= 0)
        {
            if (matrix[row * cols + col] == number)
            {
                isFound = true;
                break;
            }
            else if (matrix[row * cols + col] > number)
            {
                --col;
            }
            else
            {
                ++row;
            }
        }
    }
    return isFound;
}
```
从数组左下角到右上角遍历
```C++
// from bottom-left to top right
bool find(int* matrix, int rows, int cols, int number)
{
    bool isFound = false;
    if (matrix != NULL && rows > 0 && cols > 0)
    {
        int row = rows - 1, col = 0;
        while (col < cols && row >= 0)
        {
            if (matrix[row * cols + col] == number)
            {
                isFound = true;
                break;
            }
            else if (matrix[row * cols + col] < number)
            {
                ++col;
            }
            else
            {
                --row;
            }
        }
    }
    return isFound;
}
```