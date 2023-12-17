#include<bits/stdc++.h>
using namespace std;

void rev_arr(int *arr, int n, int i){
    if(i>= n/2)return;
    swap(arr[i], arr[n-i-1]);
    rev_arr(arr, n, i+1);
}
int main()
{
    int n; cin>>n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    rev_arr(a, n, 0);

    for(int i = 0; i<n; i++){
        cout<<a[i]<<" ";
    }cout<<endl;
    return 0;
}