# 49. 把字符串转换成整数
## 题目
> 实现函数StrToInt，把字符串转换成整数

## 注意事项
1. 功能测试（输入的字符串表示正数、负数和0）
2. 边界值测试（最大的正整数、最小的负整数）
3. 特殊输入测试（输入字符串为NULL指针、输入字符串为空字符串、输入的字符串中有非数字字符等）

## 参考代码
```C++
enum Status{ kValid = 0, kInvalid };
int g_nStatus = kVaild;
int StrToInt(const char* str)
{
    g_nStatus = kInvalid;
    long long num = 0;
    if (str != NULL && *str != '\0')
    {
        bool minus = false;
        if (*str == '+')
            str++;
        else if (*str == '-')
        {
            str++;
            minus = true;
        }
        if (*str != '0')
        {
            num = StrToIntCore(str, minus);
        }
    }
    return (int)num;
}

long long StrToIntCore(const char* digit, bool minus)
{
    long long num = 0;
    while (*digit != '\0')
    {
        if (*digit >= '0' && *digit <= '9')
        {
            int flag = minus ? -1 : 1;
            num = num * 10 + flag * (*digit - '0');
            if ((!minus && num > 0x7FFFFFFF) || (minus && num < (signed int)0x80000000))
            {
                num = 0;
                break;
            }
            digit++;
        }
        else
        {
            num = 0;
            break;
        }
    }
    if (*digit == '\0')
    {
        g_nStatus = kValid;
    }
    return num;
}
```