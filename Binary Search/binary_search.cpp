#include <bits/stdc++.h>
using namespace std;

void binarySearch(vector<int> &v, int x)
{
    int lo = 0, hi = v.size() - 1;
    int mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (v[mid] < x)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    if (v[lo] == x)
    {
        cout << lo << " " << v[lo] << endl;
    }
    else if (v[hi] == x)
    {
        cout << hi << " " << v[hi] << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int LowerBound(vector<int>&v,int x){
    int lo = 0 , hi = v.size()-1;
    int mid;
    while(hi - lo > 1){
        mid = (hi+lo)>>1;
        if(v[mid] < x){
            lo = mid+1;
        }else{
            hi = mid;
        }
    }
    if(v[lo]>=x){
        return v[lo];
    }else if(v[hi]>=x){
        return v[hi];
    }else{
        return -1;
    }
}
int UpperBound(vector<int>&v,int x){
    int lo = 0 , hi = v.size()-1;
    int mid;
    while(hi - lo > 1){
        mid = (hi+lo)>>1;
        if(v[mid] <= x){
            lo = mid+1;
        }else{
            hi = mid;
        }
    }
    if(v[lo]>x){
        return v[lo];
    }else if(v[hi]>x){
        return v[hi];
    }else{
        return -1;
    }
}

int main()
{
    int n, to_find;
    cin >> n >> to_find;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    // binarySearch(v, to_find);
    int lb = LowerBound(v,to_find);
    cout<<lb<<endl;
    int ub = UpperBound(v,to_find);
    cout<<ub<<endl;
    
    
    return 0;
}