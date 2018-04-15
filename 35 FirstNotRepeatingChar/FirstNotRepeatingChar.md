# 35 第一个只出现一次的字符
## 题目
> 在字符串中找出第一个只出现一次的字符。
## 思路
* 利用哈希表来存储元素及其出现的次数

## 参考代码
```C++
char FirstNotRepeatingChar(char* pString)
{
    if (pString == NULL)
        return '\0';
    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    for (unsigned int i = 0; i < tableSize; ++i)
        hashTable[i] = 0;
    char* pHashKey = pString;
    while (*pHashKey != '\0') 
        hashTable[*(pHashKey++)]++;
    pHashKey = pString;
    while (*pHashKey != '\0')
    {
        if (HashTable[*pHashKey] == 1)
            return *pHashKey;
        pHashKey++;
    }
    return '\0';
}
```
---
## 相关题目
1. 定义一个函数，输入两个字符串，从第一个字符串中删除在第二个字符串中出现过的所有字符。
* 使用hashTable或者set存储表第二个字符串。遍历第一个字符串时查找hashTable或者set，删除制定的元素。
```C++
string delete_solution(string str1, string str2)
{
	if (str2.empty())
		return str1;
	if (str1.empty())
		return "";
	unordered_set<char> s(str2.begin(), str2.end());
	for (auto iter = str1.begin(); iter != str1.end(); ++iter)
	{
		if (s.count(*iter))
			str1.erase(iter);
	}
	return str1;
}
```
2. 定义一个函数，删除字符串中所有重复出现的字符。
* 定义一个bool型哈希表，判断元素是否出现
```C++
string delete_solution2(string str)
{
	if (str.empty())
		return "";
	vector<bool> hashTable(256, false);
	for (auto iter = str.begin(); iter != str.end();)
	{
		if (hashTable[*iter] == false)
		{
			hashTable[*iter++] = true;
		}
		else
		{
			str.erase(iter);
		}
	}
	return str;
}
```