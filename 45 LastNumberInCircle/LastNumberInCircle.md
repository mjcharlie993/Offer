# 45 圆圈中最后剩下的数字
## 题目
> 0，1，...，n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字
## 思路一
1. 经典解法，用环形链表模拟圆圈
2. 利用std::list模拟链表
3. 每当迭代器扫描到链表末尾时，要把迭代器移到链表的头部

## 思路二
1. 创新解法
2. 定义一个关于m和n的方程，f(n,m)表示每次在n个数字中每次删除第m个数字最后剩下的数字
3. 第一个被删除的数字是(m-1)%n,记为k，下次删除从k+1开始，相当于从k+1~n-1~0~k-1。记为f`(n-1, m)
4. 最初序列剩下的数字f(n,m)一定是删除一个数字之后的序列最后剩下的数字，即f(n,m)=f`(n-1,m)
5. 将剩下n-1个数字做一个映射，映射结果形成一个0到n-2的序列，即k+1~0,k+2~1,n-1~n-k-2,0~n-k-1,1~n-k,k-1~n-2
6. 将这个映射定义为p，p(x)=(x-k-1)%n,逆映射为p(-1)=(x+k+1)%n
7. 代换后得到递归公式
8. f(n,m)=0(n=1) f(n,m)=[f(n-1,m)+m]%n(n>1)


## 参考代码一
```C++
int LastRemaining(unsigned int n, unsigned int m)
{
    if (n < 1 || m < 1)
        return -1;
    unsigned int i = 0;
    list<int> numbers;
    for (i = 0; i < n; ++i)
        numbers.push_back(i);
    list<int>::iterator current = numbers.begin();
    while (numbers.size() > 1)
    {
        for (int i = 1; i < m; ++i)
        {
            current++;
            if (current == numbers.end())
                current = numbers.begin();
        }
        list<int>::iterator next = ++current;
        if (next == numbers.end())
            next = numbers.begin();
        --current;
        numbers.erase(current);
        current = next;
    }
    return *current;
}
``` 

## 参考代码二
```C++
int LastRemaining(unsigned int n, unsigned int m)
{
    if (n < 1 || m < 1)
        return -1;
    int last = 0;
    for (int i = 2; i <= n; i++)
        last = (last + m) % i;
    return last;
}
```