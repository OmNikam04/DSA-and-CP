#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int rowSize = matrix.size();
        vector<vector<int>>nums(rowSize, vector<int>(rowSize, 0));

        for(int i =0 ; i<rowSize; i++){
            for(int j =0; j<rowSize; j++){
                nums[j][rowSize-i-1] = matrix[i][j];
            }
        }
        matrix = nums;
    }
};

int main()
{
    int row;
    cin >> row;
    int col;
    cin >> col;
    vector<vector<int>> matrix;

    for (int i = 0; i < row; i++)
    {
        vector<int> temp;
        for (int j = 0; j < col; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }
    Solution s;
    s.rotate(matrix);
    for(auto it:matrix){
        for(auto ele:it){
            cout<<ele<<" ";
        }cout<<endl;
    }
    return 0;
}