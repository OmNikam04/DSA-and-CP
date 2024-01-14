#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9+9;
const int P = 31;

// pattern = 's', Text = 't'
// pattern is string a and test is string s

vector<int> RabinKarp(const string &s, const string &t){
    int S = s.size(), T = t.size();

    for(auto it: t)
        cout<<it<<"\t";
    cout<<endl;
    // First calculate all P^i values
    vector<ll> p_pow(max(S, T));
    p_pow[0] = 1;
    for(int i = 1; i<p_pow.size(); i++)
        p_pow[i] = (p_pow[i-1] * P) % MOD;
    
    // Calculate hash values for string 's'
    vector<ll>h(T+1, 0);
    for(int i = 0; i< T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % MOD;
    
    // Calculate total hash value for string 'a'
    ll h_s = 0;
    for(int i = 0; i < S; i++)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
    
    vector<int> occurences;
    for(int i = 0; i + S -1 < T; i++){
        ll curr_h = (h[i+S] + MOD - h[i]) % MOD;
        if(curr_h == h_s * p_pow[i] % MOD)
            occurences.push_back(i);
    }

    return occurences;
}

int main(){
    string s = "aabbababbbabaa";
    string a = "aba"; // string to search in string 's'

    RabinKarp(a, s);
}