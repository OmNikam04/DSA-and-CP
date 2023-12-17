// Todo: https://www.spoj.com/problems/EKO/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e6+10;
int n;
ll m;
ll trees[N];
bool isWoodSufficient(int h){
    ll wood = 0;
    for(int i= 0; i<n; i++){
        if(trees[i]>=h){
            wood+=(trees[i]-h);
        }
    }
    return wood>=m;
}
int main()
{
    cin>>n>>m;
    for(int i = 0; i<n; i++)cin>>trees[i];
    ll lo = 0 , hi = 1e9, mid;
    while(hi-lo>1){
        mid = (hi + lo)/2;
        if(isWoodSufficient(mid)){
            lo = mid;
        }else{
            hi = mid - 1;
        }
    } 
    if(isWoodSufficient(hi)){
        cout<<hi<<endl;
    }else{
        cout<<lo<<endl;
    }
    return 0;
}