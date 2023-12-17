#include<bits/stdc++.h>
using namespace std;

// void subsequence(int index, vector<int>&ds, int *arr, int n){
    // if(index>=n){
    //     if(ds.size()==0){
    //         cout<<"{}"<<endl;
    //     }
    //     for(auto it:ds){
    //         cout<<it<<" ";
    //     }cout<<endl;
        
    //     return;
    // }
    // // Case1: take particular index into subsequence 
    // ds.push_back(arr[index]);
    // subsequence(index+1, ds, arr, n);
    // ds.pop_back();
    // // Case2: not take particular index into subsequnce
    // subsequence(index+1, ds, arr, n);
// }

void subsequence(int ind, vector<int>&ds, int arr[], int n){
    if(ind >= n){
        // break condition
        if(ds.size()==0){
            cout<<"{}"<<endl;
        }
        else{
            for(auto it: ds)
                cout<<it<<" ";
            cout<<endl;
        }
        return;
    }

    ds.push_back(arr[ind]);
    subsequence(ind+1, ds, arr, n);
    ds.pop_back();

    subsequence(ind+1, ds, arr, n);
}
int main()
{
    int a[] = {3, 1, 2} ;
    int n = sizeof(a)/sizeof(int);
    vector<int>ds;
    subsequence(0, ds, a, n);
    return 0;
}