# 33 把数组排成最小的数
## 题目
> 输入一个正整数数组，把数组里所有数字拼接起来排成了一个数，打印能拼接出的所有数字中最小的的一个。
## 思路
1. 涉及到大数问题，首先将数字转换成字符串
2. 把字符串按照排列法则字典序排列
3. 把排序的字符串组合到一起即可
## 参考代码
```C++
string PrintMinNumber(vector<int> numbers) 
{
    string str;
    if (numbers.empty())
        return "";
    vector<string> svec(numbers.size());
    for (int i = 0; i < numbers.size(); ++i)
    {
        stringstream ss;
        ss << numbers[i];
        ss >> svec[i];
    }
    sort(svec.begin(), svec.end(), compare);
    for (auto& s : svec)
        str += s;
    return str;
}
    
static bool compare(const string& s1, const string& s2)
{
    return s1 + s2 < s2 + s1;
}
```