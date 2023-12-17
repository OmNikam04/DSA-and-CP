#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPossible(vector<ll>&v, int cutterHeight, int mid){
    ll obtainedWood = 0;
    for(auto it: v){
        if(it >= mid){
            obtainedWood += (it-mid);
        }
    }
    return obtainedWood <= cutterHeight;
}

ll solve(vector<ll>&v, int n, int m)
{
    ll low = 1;
    ll high = 1e9+10;
    while(low<=high){
        ll mid = (high+low)/2;
        if(isPossible(v, m, mid)){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }               
    return low;
}

int main()
{
    ll n; cin>>n;
    ll m; cin>>m;
    vector<ll>v(n);
    for(auto &it: v)cin>>it;
    ll ans = solve(v, n, m);
    cout<<ans<<endl;
    return 0;
}