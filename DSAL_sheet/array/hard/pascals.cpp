#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int nCr(int n, int r){
        long long res =1 ;
        for(int i =0 ;i<r; i++){
            res *= (n-i);
            res /= (i+1);
        }
        return res;
    }

    vector<int> printRow(int n){
        int ans = 1;
        vector<int>temp;
        temp.push_back(ans);
        for(int i = 1; i<n; ++i){
            ans = ans * (n-i);
            ans = ans / i;
            temp.push_back(ans);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;

        for(int i = 1; i<=numRows; i++){
            ans.push_back(printRow(i));
        }

        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution s;
    vector<vector<int>> ans = s.generate(n);
    for(auto ele: ans){
        for(auto it: ele){
            cout<<it<<" ";
        }cout<<endl;
    }
    return 0;
}