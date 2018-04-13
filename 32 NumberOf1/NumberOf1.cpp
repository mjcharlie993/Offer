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