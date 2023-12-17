#include<bits/stdc++.h>
using namespace std;


void func(int ind, int sum, vector<int>&v, vector<int>&subsets){
    if(ind == v.size()){
        subsets.push_back(sum);
        return;
    }

    //pick condition
    sum+=v[ind];
    func(ind+1, sum, v, subsets);
    sum-= v[ind];

    func(ind+1, sum, v, subsets);
}
int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(auto &it: v)cin>>it;

    vector<int>subsets;
    func(0, 0,v, subsets);

    sort(subsets.begin(), subsets.end());

    for(auto it: subsets)cout<<it<<" ";
    cout<<endl; 
    return 0;
}