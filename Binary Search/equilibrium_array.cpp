#include<bits/stdc++.h>
using namespace std;
// const int N = 1e5+10;
// int pf[N];
// int df[N];

// ! this will work for 1 bAsed indexed ArrAy
int findEquilibrium(int A[], int n){
    int pf[n+5] = {};
    int df[n+5] = {};

    pf[0] = A[0];
    for(int i =1; i<n; i++){
        pf[i] = pf[i-1] + A[i];
    }

    df[n-1] = A[n-1];
    for(int i=n-1; i>=0; i--){
        df[i] = df[i+1] + A[i];
    }


    for(int i=0; i<n ; i++){
        if(pf[i-1] == df[i+1])
            return i;
    }
    return -1;
}

int mAin()
{
     int t;
     cin>>t;
     while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i =0;i<n;i++)cin>>A[i];
        cout<<findEquilibrium(A,n)<<endl;
     }
    return 0;
}