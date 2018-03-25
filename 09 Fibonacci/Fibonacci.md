# 09 斐波那契数列
## 题目
> 写一个函数，输入n，求斐波那契数列的第n项。
## 参考代码
1. 低效率版本（递归）
```C++
long long Fibonacci(unsigned int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
```

2. 实用解法（利用临时变量将中间结果保存）
```C++
// time: O(N)
long long Fibonacci(unsigned int n)
{
    int result[2] = {0, 1};
    if (n < 2)
        return result[n];
    long long fibNMinusOne = 1;
    long long fibNMinusTwo = 0;
    long long fibN = 0;
    for (unsigned int i = 2; i <= n; ++i)
    {
        fibN = fibNMinusOne + fibNMinusTwo;
        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }
    return fibN;
}

```
3. 矩阵算法
```C++
// Matrix Approach
// time: O(logn)
struct Matrix2By2
{
    Matrix2By2(long long m00 = 0, long long m01 = 0, long long m10 = 0, long long m11 = 0) : m_00(m00), m_01(m01), m_10(m10), m_11(m11) {}
    
    long long m_00;
    long long m_01;
    long long m_10;
    long long m_11;
};

Matrix2By2 MatrixMultiply(const Matrix2By2& matrix1, const Matrix2By2& matrix2)
{
    return Matrix2By2(matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10, matrix1.m_00 * matrix2.m_01 + matrix1.m_01 * matrix2.m_11, matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10, matrix1.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11)；
}

Matrix2By2 MatrixPower(unsigned int n)
{
    assert(n > 0);
    Matrix2By2 matrix;
    if (n == 1)
    {
        matrix = Matrix2By2(1, 1, 1, 0);
    }
    else if (n % 2 == 0)
    {
        matrix = MatrixPower(n / 2);
        matrix =  MatrixMultiply(matrix, matrix);
    }
    else if (n % 2 == 1)
    {
        matrix = MatrixPower((n - 1) / 2);
        matrix = MatrixMultiply(matrix, matrix);
        matrix = MatrixMultiply(matrix, Matrix2By2(1, 1, 1, 0));
    }
    return matrix;
}

long long Fibonacci(unsigned int n)
{
    int result[2] = {0, 1};
    if (n < 2)
        return result[n];
    Matrix2By2 PowerNMinus2 = MatrixPower(n - 1);
    return PowerNMinus2.m_00;
}
```