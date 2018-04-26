# 53 正则表达式匹配
## 题目
> 请实现一个函数用来匹配含有'.'和'*'的正则表达式。模式中字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次。

## 思路
1. 如果模式中ch = '.'，那么可以匹配字符串中任意字符
2. 如果模式中ch != '.'，字符串中字符是ch，那么相互匹配
3. 如果模式中ch = '*'，那么模式向后移动两个字符，
4. 如果模式中ch = '*'，且前一个字符匹配。那么字符串向右移动一个字符，模式串向右移动两个字符或零个字符。或者字符串不动，模式串向右移动两个字符

## 参考代码
```C++
bool match(char* str, char* pattern)
{
    if (str == NULL || pattern == NULL)
        return false;
    return matchCore(str, pattern);
}

bool matchCore(char* str, char* pattern)
{
    if (*str == '\0' && *pattern == '\0')
        return true;
    if (*str != '\0' && *pattern == '\0')
        return false;
    if (*(pattern+1) == '*')
    {
        if (*pattern == *str || (*pattern == '.' && *str != '\0'))
            return matchCore(str+1, pattern+2) || matchCore(str+1, pattern) || matchCore(str, pattern+2);
        else
            return matchCore(str, pattern+2);
    }
    if (*str == *pattern || (*pattern == '.' && *str != '\0'))
        return matchCore(str+1, pattern+1);
    return false;
}
```