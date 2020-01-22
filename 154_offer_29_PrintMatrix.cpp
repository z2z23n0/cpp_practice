//
// Created by Zeno on 2020/1/22.
//

class Solution {
    vector<int> v;
public:
    void PrintMatrixInCircle(vector<vector<int>> matrix, int columns, int rows, int start)
    {
        int endX = columns - 1 - start;
        int endY = rows - 1 - start;

        //从左到右打印一行
        for(int i = start; i <= endX; ++i)
        {
            v.push_back(matrix[start][i]);
        }

        //从上到下打印一列
        if(start < endY)
        {
            for(int i = start + 1; i <= endY; ++i)
            {
                v.push_back(matrix[i][endX]);
            }
        }

        //从右到左打印一行
        if(start < endX && start < endY)
        {
            for(int i = endX - 1; i >= start; --i)
            {
                v.push_back(matrix[endY][i]);
            }
        }

        //从下到上打印一列
        if(start < endX && start < endY - 1)
        {
            for(int i = endY - 1; i >= start + 1; --i)
            {
                v.push_back(matrix[i][start]);
            }
        }
    }
    vector<int> printMatrix(vector<vector<int>> matrix) {
        if(matrix.size() == 0)
        {
            return v;
        }

        int columns = matrix.size();
        int rows = matrix[0].size();
        int start = 0;
        while(columns > start * 2 && rows > start * 2)
        {
            PrintMatrixInCircle(matrix, columns, rows, start);
            start++;
        }
        return v;
    }
};
