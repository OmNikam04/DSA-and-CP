#include<bits/stdc++.h>
using namespace std;

void solve(){
     int n,m;
        cin>>n>>m;
        string fs,s;
        cin>>fs>>s;
        int cnt = 0;
        // string t = x+x;
        if(fs.find(s)!=string::npos)
            cout<<0<<endl;
        else{
            bool flag = false;
            while(fs.find(s)==string::npos){
                if(fs.length()>m*n && fs.find(s)==string::npos){
                    flag = true;
                    break;
                }
                fs=fs+fs;
                cnt++;
            }
            if(flag) cout<<-1<<endl;
            else cout<<cnt<<endl;
        }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
       solve();
    return 0;
}