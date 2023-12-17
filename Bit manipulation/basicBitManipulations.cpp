#include<bits/stdc++.h>
using namespace std;
void printBinary(int n){
    for(int i = 3; i>=0; i--){
        cout<<((n>>i)&1);
    }cout<<endl;
}
int countSetBit(int n){
    int ct = 0;
    while(n!=0){
        n = n &(n-1);
        ct++;
    }
    return ct;
}
void removeLastSetBit(int n){
    printBinary(n&(n-1));
}
void check_ith_bit_set_or_Not(int n, int i){
    if((1<<i)&n){
        cout<<"Bit is set"<<endl;
    }else{
        cout<<"Bit is unset"<<endl;
    }
}
void extract_ith_bit(int n , int i){
    cout<<((n>>i)&1)<<endl;
}

void set_ith_bit(int n, int i){
    // cout<<(n|(1<<i))<<endl;
    printBinary(n|(1<<i));

}
void clear_ith_bit(int n, int i){
    printBinary(n&(~(1<<i)));
}
void toggle_ith_bit(int n, int i){
    printBinary(n^(1<<i));
}
int main()
{
    int n;
    cin>>n;
    printBinary(n);

    int i = 1;
    check_ith_bit_set_or_Not(n,i);

    extract_ith_bit(n,i);

    set_ith_bit(n,i);

    clear_ith_bit(n,i);

    cout<<"Toggle: "<<endl;
    toggle_ith_bit(n,i);
    removeLastSetBit(n);
    // checking count of set bits in a number
    int a = countSetBit(n);
    cout<<a<<endl;
    return 0;
}