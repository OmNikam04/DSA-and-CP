

#include<bits/stdc++.h>
using namespace std;

// approach 1 using extra data structure
void all_permutations(vector<int>&v, vector<int>&ds, vector<vector<int>>&ans, vector<bool>& flag){
    if(ds.size() == v.size()){
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i<v.size(); i++){
        // if flag[i] is false then only do the operations
        if(!flag[i]){
            flag[i] = true;
            ds.push_back(v[i]);
            all_permutations(v, ds, ans, flag);
            ds.pop_back();
            flag[i] = false;
        }
    }
}

// approach 2 without using any data strucuter only swapping

void all_permute(int ind, vector<int>& nums, vector<vector<int>>& ans){
    if(ind == nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i = ind; i<nums.size(); i++)
    {
        swap(nums[ind], nums[i]);
        all_permute(ind+1, nums, ans);
        swap(nums[ind], nums[i]);
    }
}

int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(auto &it: v)cin>>it;

    vector<int>ds;
    vector<vector<int>>ans;
    vector<bool>flag(n, false);

    // all_permutations(v, ds, ans, flag); 
    all_permute(0, v, ans); 

    for(auto it: ans){
        for(auto ele: it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}