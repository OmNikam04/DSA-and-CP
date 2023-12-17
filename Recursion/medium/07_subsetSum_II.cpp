#include<bits/stdc++.h>
using namespace std;

void func(int ind, vector<int>& v, vector<int>& ds, vector<vector<int>>& ans){
    ans.push_back(ds);

    for(int i = ind; i<v.size(); i++){
        // check if duplicate elements is not picked
        if(i>ind && v[i] == v[i-1])continue;

        ds.push_back(v[i]);
        func(i+1, v, ds, ans);
        ds.pop_back();
    }
}

int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(auto &it: v)cin>>it;

    vector<int>ds;
    vector<vector<int>>ans;
    func(0, v, ds, ans); 

    for(auto it: ans){
        for(auto ele: it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}