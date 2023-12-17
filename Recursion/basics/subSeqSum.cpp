#include<bits/stdc++.h>
using namespace std;

bool subSeqSum(int i, vector<int>&ds, int initial_sum, int req_sum, int a[], int n){
    if(i==n){
        // condition satified
        if(initial_sum == req_sum){
            for(auto it: ds)cout<<it<<" ";
            cout<<endl;
            return true;
        }
        // condition not satisfied
        else return false;
    }
    // pick condition
    ds.push_back(a[i]);
    initial_sum += a[i];
    if(subSeqSum(i+1, ds, initial_sum, req_sum, a, n) == true) return true;
    ds.pop_back();
    initial_sum -= a[i];

    // not pick condition
    if(subSeqSum(i+1, ds, initial_sum, req_sum, a, n) == true) return true;

    return false;

}
// int subSeqSum(int i, vector<int>&ds, int initial_sum, int req_sum, int a[], int n){
//     if(i==n){
//         // condition satified
//         if(initial_sum == req_sum){
//             return 1;
//         }
//         // condition not satisfied
//         else return 0;
//     }
//     // pick condition
//     ds.push_back(a[i]);
//     initial_sum += a[i];
//     int l = subSeqSum(i+1, ds, initial_sum, req_sum, a, n);
//     ds.pop_back();
//     initial_sum -= a[i];

//     // not pick condition
//     int r = subSeqSum(i+1, ds, initial_sum, req_sum, a, n);

//     return l + r;

// }

int main()
{
    int a[] = {1,2,1};
    int n = sizeof(a)/ sizeof(int);
    int req_sum = 2;
    vector<int> ds;
//    subSeqSum(0, ds, 0, req_sum, a, n);
    bool ans = subSeqSum(0, ds, 0, req_sum, a, n);
    // cout<<ans;

    return 0;
}