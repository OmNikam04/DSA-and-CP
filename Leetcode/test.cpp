#include <bits/stdc++.h>
using namespace std;

void subSeq(vector<int> &v, int ind, int sum, vector<vector<int>> &ans, vector<int> &ds)
{
    
    if (ind > v.size()) {
        if(sum > 0)
        return;
    }

    if (sum == 0)
    {
        ans.push_back(ds);
        return;
    }

    // pick condition
    if (v[ind] <= sum)
    {
        ds.push_back(v[ind]);
        sum-=v[ind];
        subSeq(v, ind + 1, sum, ans, ds);
        sum+=v[ind];
        ds.pop_back();
    }

    // not pick condition
    subSeq(v, ind + 1, sum, ans, ds);
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
    vector<vector<int>> res;
    vector<int> ds;

    subSeq(v, 0, sum, res, ds);
    for (auto it : res)
    {
        for (auto ele : it)
            cout << ele << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}