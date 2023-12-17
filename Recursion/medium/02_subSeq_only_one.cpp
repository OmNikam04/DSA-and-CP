#include <bits/stdc++.h>
using namespace std;

bool subSeq(vector<int>&v, int ind, int sum, int k, vector<int>&ds){

    if(ind == v.size()){
        if(sum == k){
            for(auto it: ds)cout<<it<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }

    // pick condition
    ds.push_back(v[ind]);
    k+=v[ind];
    if(subSeq(v, ind+1, sum, k, ds)==true){
        return true;
    }
    k-=v[ind];
    ds.pop_back();

    // not pick condition
    if(subSeq(v, ind+1, sum, k, ds) == true){
        return true;
    }

    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int sum;
    cin >> sum;
    vector<int> ds;

    subSeq(v, 0, sum, 0, ds);

    return 0;
}