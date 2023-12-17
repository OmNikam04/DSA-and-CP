#include<bits/stdc++.h>
using namespace std;

string rev_string(int i , string str){
    
    int n = str.size();
    if(i>=n/2){
        return str;
    }
    swap(str[i], str[n-i-1]);
    rev_string(i+1, str);
    return "no";
}

int main()
{
    string str;
    cin>>str;
    string rev = rev_string(0, str);
    if(str.compare(rev))cout<<"Palindrome";
    else cout<<"Not palindrome";
    return 0;
}