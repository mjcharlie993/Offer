# 32 从1到n整数中1出现的次数
## 题目
> 输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。

## 算法1(X = 1)
* 当计算右数第i位包含的X的个数时：
1. 取第i位左边(高位)的数字，乘以10^(i-1)，得到基础值a
2. 取第i位数字，计算修正值
    1. 如果大于X，则结果为a+10^(i-1)
    2. 如果小于X，则结果为a
    3. 如果等于X，则取第i位右边(低位)数字，设为b，结果为a+b+1

## 参考代码
```C++
int NumberOf1Between1AndN(int n)
{
	int count = 0;
	int a = n, b = 0;
	int base = 1;
	while (a)
	{
		b = a % 10;
		a = a / 10;
		count += a * base;
		if (b > 1)
			count += base;
		else if (b == 1)
			count += (n % base) + 1;
		base *= 10;
	}
	return count;
}
```
```C++
int NumberOf1Between1AndN(int n)
{
	int count = 0;
    for (int i = 1; i <= n; i *= 10)
    {
        int a = n / i;
        int b = n % i;
        count += (a + 8) / 10 * i + ((a % 10 == 1) ? b + 1 : 0);
    }
	return count;
}

```