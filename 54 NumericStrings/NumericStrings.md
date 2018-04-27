# 表示数值的字符串
## 题目
> 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）
## 思路
* [sign]integral-digits[.[fractional-digits]][e|E[sign]exponential-digits]
## 参考代码
```C++
bool isNumeric(char* string)
{
    if (string == NULL)
        return false;
    if (*string == '+' || *string == '-')
        ++string;
    if (*string == '\0')
        return false;
    bool numeric = true;
    scanDigits(&string);
    if (*string != '\0')
    {
        if (*string == '.')
        {
            ++string;
            scanDigits(&string);
            if (*string == 'e' || *string == 'E')
                numeric = isExponential(&string);
        }
        else if (*string == 'e' || *string == 'E')
            numeric = isExponential(&string);
        else
            numeric = false;
    }
    return numeric && *string != '\0';
}

void scanDigits(char** string)
{
    while (**string != '\0' && **string >= '0' && **string <= '9')
        ++(*string);
}

bool isExponential(char** string)
{
    if (**string != 'e' && **string != 'E')
        return false;
    ++(*string);
    if (**string == '+' || **string == '-')
        ++(*string);
    if (**string == '\0')
        return false;
    scanDigits(string);
    return (**string == '\0') ? true : false;
}
```