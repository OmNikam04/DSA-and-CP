#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
            for (int j = i+1; j < prices.size(); j++)
                profit = max(prices[j]-prices[i], profit);
        
        return profit;
    }

    int maxProfitBetter(vector<int>& prices){
        int mini = prices[0];
        int profit = 0;
        for(int i = 1; i<prices.size(); i++){
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(prices[i], mini);
        }
        return profit;
    }
};

int main()
{
    int n; cin>>n;
    vector<int> v;
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    Solution solution;
    int ans = solution.maxProfitBetter(v);
    cout<<ans<<endl;
    return 0;
}