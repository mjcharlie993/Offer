// from top-right to bottom-left
bool find(int* matrix, int rows, int cols, int number)
{
    bool isFound = false;
    if (matrix != NULL && rows > 0 && cols > 0)
    {
        int row = 0, col = cols - 1;
        while (row < rows && col >= 0)
        {
            if (matrix[row * cols + col] == number)
            {
                isFound = true;
                break;
            }
            else if (matrix[row * cols + col] > number)
            {
                --col;
            }
            else
            {
                ++row;
            }
        }
    }
    return isFound;
}

// from bottom-left to top right
bool find(int* matrix, int rows, int cols, int number)
{
    bool isFound = false;
    if (matrix != NULL && rows > 0 && cols > 0)
    {
        int row = rows - 1, col = 0;
        while (col < cols && row >= 0)
        {
            if (matrix[row * cols + col] == number)
            {
                isFound = true;
                break;
            }
            else if (matrix[row * cols + col] < number)
            {
                ++col;
            }
            else
            {
                --row;
            }
        }
    }
    return isFound;
}