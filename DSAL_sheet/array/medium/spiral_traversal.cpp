#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        vector<int> ans;

        int row_start = 0, col_start = 0;
        int row_end = rowSize - 1, col_end = colSize - 1;

        while ((row_start <= row_end) && (col_start <= col_end))
        {
            for (int i = col_start; i <= col_end; i++)
                ans.push_back(matrix[row_start][i]);
            row_start++;

            for (int i = row_start; i <= row_end; i++)
                ans.push_back(matrix[i][col_end]);
            col_end--;

            if (row_start <= row_end)
            {
                for (int i = col_end; i >= col_start; --i)
                    ans.push_back(matrix[row_end][i]);
                row_end--;
            }

            if (col_start <= col_end)
            {
                for (int i = row_end; i >= row_start; --i)
                    ans.push_back(matrix[i][col_start]);
                col_start++;
            }
        }

        return ans;
    }
};
int main()
{
    vector<vector<int>> nums;
    int rowSize;
    int colSize;
    cin >> rowSize;
    cin >> colSize;
    for (int i = 0; i < rowSize; i++)
    {
        vector<int> temp;
        for (int j = 0; j < colSize; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        nums.push_back(temp);
    }
    Solution s;
    vector<int> ans = s.spiralOrder(nums);
    for (auto it : ans)
        cout << it << " ";

    return 0;
}