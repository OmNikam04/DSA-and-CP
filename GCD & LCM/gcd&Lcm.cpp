#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    // if(a%b == 0)return b; //!This same as below but '%' operation cost a lot
    if(b == 0)return a;
    return gcd(b,a%b);
}

int lcm(int a, int b){
    return (a*b/(gcd(a,b)));
}
int main()
{
    int a, b;
    cin >> a >> b;

    // ? Time complexity for gcd : O(log(n))
    int c = gcd(a,b);
    cout<<__gcd(a,b)<<" "<<c<<endl;
    int d = lcm(a,b);
    cout<<d<<endl;
    return 0;
}