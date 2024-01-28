#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int dp[102][1002];
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    
    int knapsack(vector<int>&weight, vector<int>&value, int capacity, int n){
        // base condition
        if(n == 0 || capacity == 0)
            return 0;
        if(dp[n][capacity] != -1)
            return dp[n][capacity];
        
        if(weight[n-1] <= capacity)
            return dp[n][capacity] = max(value[n-1] + knapsack(weight, value, capacity - weight[n-1], n-1),
                        knapsack(weight, value, capacity, n-1));
        
        else if(weight[n-1] > capacity)
            return dp[n][capacity] = knapsack(weight, value, capacity, n-1);
    }
};


int main(){
    int n;cin>>n;
    int capacity; cin>>capacity;
    vector<int>wt(n), val(n);
    for(auto &it: wt)cin>>it;
    for(auto &it: val)cin>>it;

    Solution st;
    cout<<st.knapsack(wt, val, capacity, n)<<endl;

    return 0;
}