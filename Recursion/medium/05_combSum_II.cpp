#include<bits/stdc++.h>
using namespace std;


void combSumII(vector<int>&v, int ind, int sum, vector<vector<int>>&ans, vector<int>&ds){

    // base condition
    if(sum == 0){
        // ans.push_back(ds);
        for(auto it: ds)cout<<it<<" ";cout<<endl;
        return;
    }

    for(int i = ind; i<v.size(); i++){
        // we cannot pick the element which is duplicate
        // but we can pick the element which is currently ind so the check i > ind
        if(i > ind && v[i] == v[i-1]) continue;

        if(v[i] > sum) break;

        ds.push_back(v[i]);
        combSumII(v, i+1, sum-v[i], ans, ds);
        ds.pop_back();
    }
}

int main()
{
    int n;cin>>n;
    int sum;cin>>sum;

    vector<int>v(n);
    for(auto &it: v)cin>>it;

    sort(v.begin(), v.end());

    vector<vector<int>>ans;
    vector<int>ds;

    combSumII(v, 0, sum, ans, ds);

    for(auto it: ans)
        for(auto ele: it)
            cout<<ele<<" ";
        cout<<endl;
    cout<<endl;
    
    return 0;
}