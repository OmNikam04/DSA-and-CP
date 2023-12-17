#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void markRows(vector<vector<int>> &nums, int rows)
    {
        int colSize = nums[0].size();
        for (int i = 0; i < colSize; i++)
        {
            if (nums[rows][i] != 0)
                nums[rows][i] = -1;
        }
    }
    void markCols(vector<vector<int>> &nums, int cols)
    {
        int rowSize = nums.size();
        for (int i = 0; i < rowSize; i++)
        {
            if (nums[i][cols] != 0)
                nums[i][cols] = -1;
        }
    }
    void bruteForce(vector<vector<int>> &nums)
    {
        int rowSize = nums.size();
        int colSize = nums[0].size();

        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (nums[i][j] == 0)
                {
                    markRows(nums, i);
                    markCols(nums, j);
                }
            }
        }

        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (nums[i][j] == -1)
                {
                    nums[i][j] = 0;
                }
            }
        }
    }

    void better(vector<vector<int>> &nums)
    {
        int rowSize = nums.size();
        int colSize = nums[0].size();
        vector<int> rows(rowSize, 0);
        vector<int> cols(colSize, 0);
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (nums[i][j] == 0)
                {
                    cols[j] = 1;
                    rows[i] = 1;
                }
            }
        }

        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (rows[i] == 1 || cols[j] == 1)
                {
                    nums[i][j] = 0;
                }
            }
        }
    }

    void optimal(vector<vector<int>> &nums)
    {
        int col0 = 1;
        int rowSize = nums.size();
        int colSize = nums[0].size();

        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (nums[i][j] == 0)
                {
                    // mark the ith row
                    nums[i][0] = 0;

                    // mark the jth col
                    if (j != 0)
                        nums[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        for (int i = 1; i < rowSize; i++)
        {
            for (int j = 1; j < colSize; j++)
            {
                if (nums[i][j] != 0)
                {
                    if (nums[0][j] == 0 || nums[i][0] == 0)
                    {
                        nums[i][j] = 0;
                    }
                }
            }
        }

        // set 1st row
        if(nums[0][0] == 0){
            for(int j = 0; j<colSize; j++){
                if(nums[0][j]!=0)
                    nums[0][j] = 0;
            }
        }

        // set 1st row 
        if(col0 == 0){
            for(int i = 0; i<rowSize; i++){
                if(nums[i][0] != 0)
                    nums[i][0] = 0;
            }
        }
    }
};
int main()
{
    int row;
    cin >> row;
    int col;
    cin >> col;
    vector<vector<int>> nums;
    for (int i = 0; i < row; i++)
    {
        vector<int> v;
        for (int j = 0; j < col; j++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        nums.push_back(v);
    }
    Solution s;
    s.optimal(nums);
    for (auto it : nums)
    {
        for (auto ele : it)
            cout << ele << " ";
        cout << endl;
    }
    return 0;
}