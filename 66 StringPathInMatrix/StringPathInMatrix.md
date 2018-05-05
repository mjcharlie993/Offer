# 66 矩阵中的路径
## 题目
> 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
## 思路
1. 利用回溯法
2. 首先在矩阵中任选一个格子作为路径的起点。如果某个格子字符为ch，那么这个格子对应于路径的第i个字符。如果第i个字符不是ch，那么格子不可能在路径的第i个位置
3. 定义与字符矩阵大小一样的布尔矩阵用于判断已访问的格子

## 参考代码
```C++
bool hasPath(char* matrix, int rows, int cols, char* str)
{
    if (matrix == NULL || row < 1 || cols < 1 || str == NULL)
        return false;
    bool* visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);
    int pathLength = 0;
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
            {
                return true;
            }
        }
    }
    delete[] visited;
    return false;
}

bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str, int& pathLength, bool* visited)
{
    if (str[pathLength] == '\0')
        return true;
    bool hasPath = false;
    if (row >= 0 && col >= 0 && row < rows && col < cols && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col])
    {
        ++pathLength;
        visited[row * cols + col] = true;
        hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited) 
                || hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited) 
                || hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited) 
                || hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);
        if (!hasPath)
        {
            --pathLength;
            visited[row * cols + col] = false;
        } 
    }
    return hasPath;
}
```