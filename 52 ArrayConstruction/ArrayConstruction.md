# 构建乘积数组
## 题目
> 给定一个数组A[0,1,...,n-1]，请构建一个数组B[0,1,...,n-1]，其中B中的元素B[i]=A[0]xA[1]x...xA[i-1]xA[i+1]x...xA[n-1].不能使用除法

## 思路
1. 把B[i]=A[0]xA[1]x...xA[i-1]xA[i+1]x...xA[n-1]看出A[0]xA[1]x...xA[i-1]和A[i+1]x...xA[n-2]xA[n-1]两个部分的乘积
2. B可以用一个矩形来构造
## 参考代码
```C++
void multiply(const vector<int>& array1, vector<int>& array2)
{
    int length1 = array1.size();
    int length2 = array2.size();
    if (length1 == length2 && length2 > 1)
    {
        array2[0] = 1;
        for (int i = 1; i < length1; ++i)
            array2[i] = array2[i-1] * array1[i-1];
        double temp = 1;
        for (int i = length1 - 2; i >= 0; --i)
        {
            temp *= array1[i+1];
            array2[i] *= temp;
        }
    }
}
```