#include<bits/stdc++.h>
using namespace std;
double eps = 1e-7;
int main(){
    double n;cin>>n;
    double lo = 1, hi = n;
    double mid;
    while(hi-lo > eps){
        mid = (hi+lo)/2;
        if(mid * mid < n){
            lo = mid;
        }else{
            hi = mid;
        }
    }// after this we have lo and hi and
    // both are going to give same precise value upto epsilon we have set globally
    cout<<setprecision(10)<<lo<<endl;
    cout<<setprecision(10)<<hi<<endl;
    return 0;
}