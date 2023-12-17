#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void all_permute(int ind, vector<int>&arr, set<vector<int>>&st){
        if(ind == arr.size()){
            st.insert(arr);
            return;
        }
        for(int i = ind; i<arr.size(); ++i){
            if(i!=ind && arr[ind]==arr[i])continue;
            swap(arr[i], arr[ind]);
            all_permute(ind+1, arr, st);
            swap(arr[i], arr[ind]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>st;
        all_permute(0, nums,st);
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};
int main()
{
    int n;cin>>n;
    // int a[n];
    // for(int i=0; i<n; ++i)cin>>a[i];
    vector<vector<int>>ans;
    vector<int>ds;
    int freq[n] = {0};

    Solution s;
    // vector<vector<int>> sol = s.next_permut1(ds, freq, ans, a, n);
    vector<int>arr;
    for(int i=0; i<n; ++i){
        int x;cin>>x;
        arr.push_back(x);
    }
    vector<vector<int>> sol = s.permuteUnique(arr);
    sort(sol.begin(), sol.end());
    for(auto ele: sol){
        for(auto it: ele){
            cout<<it<<" ";
        }cout<<endl;
    }

    return 0;
}