#include<bits/stdc++.h>
using namespace std;
#define ll long long 

// recursive approach
int my_pow(ll a, ll b){

    if(b == 0) return 1;
    int tmp = my_pow(a, b/2);
    int res = tmp * tmp;
    // handling odd power
    if(b%2 == 1) res *= a;
    return res;
}

// iterative approach
int my_pow_itr(ll a, ll b){
    int res = 1;
    
    while(b > 0){
        if(b%2 == 1) res *= a;
        a *= a;
        b /= 2;
    }

    return res;
}
int main()
{
    long long a, b;
    cin>>a>>b;
    int ans = my_pow_itr(a, b);
    cout<<ans<<endl;
    return 0;
}