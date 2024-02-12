#include<bits/stdc++.h>
using namespace std;

#define lli long long int
#define fo(i,n)   for(int i=0;i<(n);++i)
#define repA(i,j,n)   for(int i=(j);i<=(n);++i)
#define repD(i,j,n)   for(int i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
using vi = vector<lli>;

const int PRIME = 31;
const int MOD = 1e9 + 9;


// This is my own implementation of Rabinkarp algorithm
vector<int> RabinKarp(string str, string patt){
    int strSize= str.size(), pattSize = patt.size();

    // 1. Creating all p^i's 
    vector<lli> ppow(max(strSize, pattSize));
    ppow[0] = 1;
    for(int i = 1; i<ppow.size(); i++)
        ppow[i] = (ppow[i-1] * PRIME) % MOD;

    // 2. Create prefix of hash values for given string
    vector<long long>hsh(strSize, 0);
    for(int i =0; i<strSize; i++)
        hsh[i] = (ppow[i] * (str[i] - 'a' + 1)) % MOD;

    vector<long long>pre_hsh(strSize+1, 0);
    pre_hsh[1] = hsh[0];
    for(int i = 2; i<strSize+1; i++)
        pre_hsh[i] = (pre_hsh[i-1] + hsh[i-1]) % MOD;
    
    
    // 3. Calculate hash value of pattern
    lli patternHash = 0;
    for(int i = 0; i<pattSize; i++){
        patternHash = (patternHash + (patt[i] - 'a' + 1) * ppow[i]) % MOD;
    }

    vector<int>ans;
    // 4. Traverse pre_hsh[] to find occurences of patternHash
    for(int i =0 ; i<= strSize - pattSize; i++){
        lli currentHash = (pre_hsh[i + pattSize] - pre_hsh[i] + MOD) % MOD;
        if(currentHash == (patternHash * ppow[i]) % MOD)
            ans.push_back(i);
    }

    return ans;
}

void solve(){
    string str = "abcdabcadsflkasdkfjlaksdabcasdfa";
    string patt = "abc";
    auto pi = RabinKarp(str, patt);
    for(auto x: pi)
        cout<<x<<" ";
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t; cin>>t;
    while(t--)
        solve();
    return 0;
}