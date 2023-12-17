#include<bits/stdc++.h>
using namespace std;
void pm(int st, int ed){
    cout<<"Moving disk from "<<st<<" to "<<ed<<endl;
}

void toh(int n, int start, int end){
    if(n == 1){
        pm(start, end);
        return;
    }

    int other = 6 - (start + end);
    toh(n-1, start, other);
    pm(start, end);
    toh(n-1, other, end);          
}

int ct = 0;
int toh_with_count(int n, int start, int end){
    ct++;
    if(n == 1){
        pm(start, end);
        return ct;
    }

    int other = 6 - (start + end);
    toh_with_count(n-1, start, other);
    pm(start, end);
    toh_with_count(n-1, other, end);     
    return ct;     
}


int main()
{
    int n;
    cin>>n;
    int a = 1, b=3;
    toh_with_count(n, 1, 3);
    cout<<ct<<endl;
    return 0;
}