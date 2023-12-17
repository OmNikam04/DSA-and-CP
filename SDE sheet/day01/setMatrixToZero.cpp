#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printVector(vector<vector<int>> &v)
    {
        for (int i = 0; i < v.size(); ++i)
        {
            for (int j = 0; j < v[i].size(); ++j)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
    void markCols(vector<vector<int>> &v, int j)
    {
        for (int i = 0; i < v.size(); ++i)
            v[i][j] = -1;
    }
    void markRows(vector<vector<int>> &v, int i)
    {
        for (int j = 0; j < v.size(); ++j)
            v[i][j] = -1;
    }
    void setZeroes(vector<vector<int>> &matrix)
    {

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    markCols(matrix, j);
                    markRows(matrix, i);
                }
            }
        }
        // set -1 with 0
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
        printVector(matrix);
    }
};

class betterSolution
{
public:
    void printVector(vector<vector<int>> &v)
    {
        for (int i = 0; i < v.size(); ++i)
        {
            for (int j = 0; j < v[i].size(); ++j)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
    void setZeros(vector<vector<int>> &v) 
    {   
        int rowSize = v[0].size();//3
        int colSize = v.size();//4
        cout<<"row"<<rowSize<< " "<<colSize<<endl;
        int row[rowSize] = {0};
        int col[colSize] = {0};
        for (int i = 0; i < rowSize; ++i)
        {
            for (int j = 0; j < colSize; ++j)
            {
                if (v[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        // for(auto it: row)cout<<it<<" ";
        // cout<<endl;
        // for(auto it: col)cout<<it<<" ";
        // cout<<endl;

        for(int i = 0; i<v .size(); ++i){
            for(int j = 0; j<v.size(); ++j){
                if(row[i] == 1 || col[j] == 1){
                    v[i][j] = 0;
                }
            }
        }

        printVector(v);
    }

    void optimal(vector<vector<int>>&v){
        // v[..][0] -> row
        // v[0][..] -> col
        int col0 = 1;
        for(int i =0 ;i < v[0].size(); i++){
            for(int j = 0; j<v.size(); j++){
                if(v[i][j] == 0){
                    v[i][0] = 0;
                    if(j != 0){
                        v[0][j] = 0;
                    }
                    else{
                        col0 = 0;
                    }
                }
            }
        }

        for(int i = 1; i<v[0].size(); ++i){
            for(int j = 1; j<v.size(); ++j){
                if(v[i][j] != 0){
                    if(v[i][0] == 0 || v[0][j] == 0){
                        v[i][j] = 0;
                    }
                }
            }
        }

        if(v[0][0] == 0)
            for(int j = 0; j < v.size(); j++) v[0][j] = 0;
        if(col0 == 0 ){
            for(int i = 0; i< v.size(); i++) v[i][0] = 0;
        }
        printVector(v);
    }
};

int main()
{
    vector<vector<int>> v_array;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        v_array.push_back(v);
    }

    // Solution s;
    // s.setZeroes(v_array);
    betterSolution s;
    s.optimal(v_array);
    return 0;
}