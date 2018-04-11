# 28 字符串的排列
## 题目
> 输入一个字符串，打印出该字符串中字符的所有排列。
## 思路
1. 把字符串分成两部分，一部分是字符串的第一个字符，另一部分是第一个字符以后的所有字符。
2. 把第一个字符和它后面的字符逐个交换
3. 递归这个过程
## 参考代码
```C++
void Permutation(char* pStr)
{
    if (pStr == NULL)
        return;
    Permutation(pStr, pStr);
}

void Permutation(char* pStr, char* pBegin)
{
    if (*pBegin == '\0')
    {
        printf("%s\n", pStr);
    }
    else
    {
        for(char* pCh = pBegin; *pCh != '\0'; ++pCh)
        {
            swap(pCh, pBegin);
            Permutation(pStr, pBegin+1);
            swap(pCh, pBegin);
        }
    }
}

void swap(char* s, char* p)
{
    char temp = *s;
    *s = *p;
    *p = temp;
}
```

## 拓展1
> 求n个字符的长度为m的组合。(1 <= m <= n)
## 思路
把求n个字符组成长度为m的组合的问题分解成两个子问题，分别求n-1个字符串中长度为m-1的组合，以及求n-1个字符的长度为m的组合。使用递归。
## 参考代码
```C++
void StringCombination(char* str)
{
	if (str == NULL)
		return;
	int length = strlen(str);
	vector<char> result;
	for (int i = 1; i <= length; ++i)
		StringCombination(str, i, result);
}

void StringCombination(char* str, int idx, vector<char>& result)
{
	if (idx == 0)
	{
		for (auto iter = result.begin(); iter != result.end(); ++iter)
			cout << *iter;
		cout << endl;
		return;
	}
	if (*str == '\0')
		return;
	result.push_back(*str);
	StringCombination(str + 1, idx - 1, result);
	result.pop_back();
	StringCombination(str + 1, idx, result);
}
```
---
## 相关题目1
1. 输入一个含有8个数字的数组，判断有没有可能把这8个数字分别放到正方体的8个顶点上，使得正方体上三组相对的面上4个顶点的和相等。
## 思路
1. 相当于先得到这a1,a2,a3,a4,a5,a6,a7,a8这8个数字的全排列
2. 然后判断有没有某一个排列符合题目给定的条件：
3. a1+a2+a3+a4==a5+a6+a7+a8 && a2+a4+a6+a8==a1+a3+a5+a7 && a1+a2+a5+a6==a3+a4+a7+a8

## 参考代码
```C++
bool isEqual(vector<int> nums)
{
	vector<vector<int>> res;
	NumberPermutation(nums, 0, res);
	for (int i = 0; i < res.size(); ++i)
	{
		if (res[i][1] + res[i][3] + res[i][5] + res[i][7] == res[i][0] + res[i][2] + res[i][4] + res[i][6] && res[i][0] + res[i][1] + res[i][2] + res[i][3] == res[i][4] + res[i][5] + res[i][6] + res[i][7] && res[i][0] + res[i][1] + res[i][4] + res[i][5] == res[i][2] + res[i][3] + res[i][6] + res[i][7])
			return true;
	}
	return false;
}

void NumberPermutation(vector<int>& nums, int idx, vector<vector<int>>& res)
{
	if (idx == 8)
	{
		res.push_back(nums);
		return;
	}
	else
	{
		for (int i = idx; i < 8; ++i)
		{
			swap(nums[i], nums[idx]);
			NumberPermutation(nums, idx + 1, res);
			swap(nums[i], nums[idx]);
		}
	}
}
// 也可以在每一步生成新排列时判断条件，这样降低算法的时间复杂度。
```
---
## 相关题目2
2. 在8x8的国际象棋上摆放8个皇后，使其不能相互攻击，即任意两个皇后不得处于同一行、同一列或者同一对角线上，请问有多少种摆放方式
##  思路
1. 每一个皇后占据一行
2. 定义一个数组ColumnIndex[i]，数组中第i个数字表示位于第i行的皇后的列号。
3. 对ColumnIndex中8个数字进行全排列。
4. 只需要对每一个排列对应的8个皇后是不是在同一对角线上进行判断，即i-j==ColumnIndex[i]-ColumnIndex[j]或者j-i==ColumnIndex[i]-ColumnIndex[j]
## 参考代码
```C++
int total = 0;
bool check(int columnIndex[], int length)
{
	for (int i = 0; i<length; i++)
	{
		for (int j = i + 1; j<length; j++)
		{
			//是否在对角线上  
			if (i - j == columnIndex[i] - columnIndex[j] || j - i == columnIndex[i] - columnIndex[j])
			{
				return false;
			}
		}
	}
	return true;
}
//全排列  
void Permutation(int columnIndex[], int length, int index)
{
	if (length == index)
	{
		if (check(columnIndex, length))
		{
			total++;
			//打印  
			for (int i = 0; i<length; i++)
			{
				printf("%d ", columnIndex[i]);
			}
			printf("\n---------------\n");
		}
	}
	else
	{
		for (int i = index; i<length; i++)
		{
			swap(columnIndex[index], columnIndex[i]);
			Permutation(columnIndex, length, index + 1);
			swap(columnIndex[index], columnIndex[i]);
		}
	}
}
void eightQueen()
{
	int queens = 8;
	int* columnIndex = new int[queens];
	for (int i = 0; i<queens; i++)
	{
		columnIndex[i] = i;
	}
	Permutation(columnIndex, queens, 0);
}
int main()
{
	eightQueen();
	printf("共有%d种", total);
	return 0;
}
```