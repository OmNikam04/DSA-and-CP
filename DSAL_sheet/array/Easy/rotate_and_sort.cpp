#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArraySorted(vector<int>& nums){
        for(int i=0; i<nums.size()-1; i++){
            int j = i+1;
            if(nums[i]>nums[j]){
                return false;
            }
        }
        return true;
    }
    int getX(vector<int>& nums){
        for(int i =0;i<nums.size();i++){
            int j = i+1;
            if(nums[j]<nums[i]){
                return j;
            }
        }
        return 0;
    }
    
    bool check(vector<int>& nums) {
        if(isArraySorted(nums))return true;
        vector<int>b;
        int x = getX(nums);
        cout<<x<<endl;
        for(int i =0; i<nums.size(); i++){
            int ind = ((i+x)%nums.size());
           b.push_back(nums[ind]);
        }
        return isArraySorted(b);
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i =0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    Solution s ;
    cout<<s.check(v);

    return 0;
}