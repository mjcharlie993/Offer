// Recursive
long long Fibonacci(unsigned int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

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

// ------------------------------------------------------------
int jumpFloor(int number) {
    int result[3] = {0, 1, 2};
    if (number < 3)
        return result[number];
    int a = 2, b = 1;
    int res = 0;
    for (int i = 3; i <= number; ++i)
    {
        res = a + b;
        b = a;
        a = res;
    }
    return res;
}
// ------------------------------------------------------------
long long result(unsigned int n)
{
    int ret = 1;
    for (int i = 2; i <= n; ++i)
    {
        ret *= 2;
    }
    return ret;
}

// ------------------------------------------------------------
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