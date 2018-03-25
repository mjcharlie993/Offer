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
# 拓展
## 题目
> 一只青蛙一次可以跳上1级台阶，也可以跳上2级，求该青蛙跳上一个n级的台阶总共有多少种跳法
## 思路
* 如果只有1级台阶，那么只有一种跳法
* 如果有2级台阶，那么就有两种跳法：一种是分两次跳，每次跳1级；另外一种是一次跳2级
* 把n级台阶的跳法看成是n的函数，记为f(n)。当n>2时，第一次跳的时候就有两种不同的选择：一是第一次只跳1级，此时跳法数目等于后面剩下的n-1级台阶的跳法数。另外一种是第一次跳2级，此时跳法总数等于后面剩下的n-2级台阶的跳法总数。所以n级台阶的不同跳法总数为
* f(n) = f(n - 1) + f(n - 2)
* 实际上就是Fibonacci数列
## 参考上述代码即可
```C++

// ------------------------------------------------------------
// Recursive
long long Fibonacci(unsigned int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}


// ------------------------------------------------------------
// Iterative
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


// ------------------------------------------------------------
// Matrix Approach
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
## 青蛙拓展
## 题目
> 一只青蛙一次可以跳上1级台阶，也可以跳上2级......它也可以跳上n级，此时该青蛙跳上一个n级台阶的总共有多少种跳法？

## 分析
1. 如果只有1级台阶，则有一种跳法
2. 如果有2级台阶，有两种跳法：1+1、2
3. 如果有3级台阶，有四种跳法：1+1+1、1+2、2+1、3
4. 每增加1级，青蛙的跳法就会呈指数上升
5. f(n) = 2^(n - 1)

## 参考代码
```C++
long long result(unsigned int n)
{
    int ret = 1;
    for (int i = 2; i <= n; ++i)
    {
        ret *= 2;
    }
    return ret;
}
```

# 相关题目
## 题目
> 我们可以用2x1的小矩形横着或竖着去覆盖更大的矩形，请问8个2x1的小矩形无重叠地覆盖一个2x8的大矩形，总共有多少种方法

## 分析
1. 覆盖大矩形有2种方法：横着或竖着
2. 竖着覆盖时，右边还剩下2x7，这时覆盖方法为f(7)
3. 横着覆盖时，则其下面必须也横放一个，右边还剩下2x6，这时覆盖方法为f(6)
4. 此时f(8) = f(7) + f(6)
5. 不难看出这仍是一个Fibonacci数列

## 参考代码如下
```C++
int cover(unsigned int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    int a = 2;
    int b = 1;
    int res = 0;
    for (int i = 3; i <= n; ++i)
    {
        res = a + b;
        b = a;
        a = res;
    }
    return res;
}
```
