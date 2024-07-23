#include<bits/stdc++.h>
using namespace std;


// TC:O(root n * log n)
// SC:O(1)
vector<pair<int, int>> primeFactors(int n){
    vector<pair<int, int>>ans;
    for(int i = 2; i*i<=n; i++){
        if(n%i==0){
            int cnt = 0;
            while(n%i==0){
                cnt++;
                n=n/i;
            }
            ans.push_back({i, cnt});
        }
    }
    // there is a number greater than root n to consider that
    if(n>1)
        ans.push_back({n, 1});
    return ans;
}

int main(){
    
    return 0;
}
