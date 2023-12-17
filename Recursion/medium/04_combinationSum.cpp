#include <bits/stdc++.h>
using namespace std;


void combSum(vector<int> &v, int ind, int sum, vector<int> &ds)
{
    // base condition
    if(ind == v.size()){
        if(sum == 0){
            for(auto it: ds)cout<<it<<" ";
            cout<<endl;
        }
        return;
    }

    // pick element only if current sum is greater than or equal to v[ind]
    if (v[ind] <= sum)
    {
        ds.push_back(v[ind]);
        sum -= v[ind];
        combSum(v, ind, sum, ds);
        sum += v[ind];
        ds.pop_back();
    }

    // not pick condition
    combSum(v, ind + 1, sum, ds);
}

int main()
{
    int n;
    cin >> n;
    int sum;
    cin >> sum;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;

    vector<int> ds;
    combSum(v, 0, sum, ds);
    
    return 0;
}