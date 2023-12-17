#include <bits/stdc++.h>
using namespace std;

int subSeq(vector<int>&v, int ind, int sum, int k, vector<int>&ds){

    if(ind == v.size()){
        if(sum == k){
            return 1;
        }
        return 0;
    }

    // pick condition
    ds.push_back(v[ind]);
    k+=v[ind];
    int left = subSeq(v, ind+1, sum, k, ds);
    k-=v[ind];
    ds.pop_back();

    // not pick condition
    int right = subSeq(v, ind+1, sum, k, ds);

    return left + right;
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

    int count = subSeq(v, 0, sum, 0, ds);
    cout<<count<<endl;

    return 0;
}