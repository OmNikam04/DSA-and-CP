#include<bits/stdc++.h>
using namespace std;

vector<int> solve(long long N){
    vector<int>ans;
    ans.push_back(1);
    ans.push_back(1);
    long long range = N-2;
    int n1 = 1;
    int n2 = 1;

    int i=2;
    while(range--){
        long long sum = n1 + n2;
        n1 = n2;
        n2 = sum;
        ans.push_back(sum);
    }

    reverse(ans.begin(), ans.end());

    return ans;

}

void solve2(long long n){
    if(n < 1)return;
    cout<<n<<endl;
    solve2(n-1);
}
int main()
{
    long long N;
    solve2(N);
    cin>>N;
    return 0;
}