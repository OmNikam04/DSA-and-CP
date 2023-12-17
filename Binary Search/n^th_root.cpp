#include <bits/stdc++.h>
using namespace std;
double eps = 1e-7;

double multiply(double mid, double nthRoot)
{
    double ans = 1;
    for (int i = 0; i < nthRoot; i++)
    {
        ans *= mid;
    }
    return ans;
}
int main()
{
    double n,x;
    cin >> n>>x;
    double lo = 1, hi = n;
    double mid;
    while (hi - lo > eps)
    {
        mid = (hi + lo) / 2;
        if (multiply(mid,x) < n)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    } // after this we have lo and hi and
    // both are going to give same precise value upto epsilon we have set globally
    cout << setprecision(10) << lo << endl;
    // But most of the time hi value is accurate so use hi instead lo
    cout << setprecision(10) << hi << endl;
    cout<<pow(n,1.0/x)<<endl;
    return 0;
}