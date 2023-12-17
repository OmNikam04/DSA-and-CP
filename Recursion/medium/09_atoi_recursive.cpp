#include <bits/stdc++.h>
using namespace std;

int stringToInt(string s, int last)
{
    if (last == 0)
        return s[last] - '0';

    int smallAns = stringToInt(s, last - 1);
    int a = s[last] - '0';
    return (int)(smallAns * 10 + a);
}
int myAtoi(string s)
{
    int n = s.size();
    return stringToInt(s, n - 1);
}

int main()
{
    string s;
    cin>>s;
    cout<<typeid(s).name()<<endl;
    int ans = myAtoi(s);
    cout<<ans<<endl;
    cout<<typeid(ans).name()<<endl;
    return 0;
}