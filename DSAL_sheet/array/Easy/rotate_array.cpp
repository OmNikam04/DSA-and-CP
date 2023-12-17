#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse(vector<int>&nums, int low, int high){
        while(low<high){
            swap(nums[low], nums[high]);
            low++;high--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        vector<int>temp;
        int n = nums.size();
        k = k%n;// most important condition
        int d = n-k-1;
        
        reverse(nums, 0 , d);
        reverse(nums, d+1, n-1);
        reverse(nums, 0, n-1);
    }
};

int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    int k;cin>>k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    Solution s;
    s.rotate(nums,k);
    for(auto it:nums)cout<<it<<" ";
    cout<<endl;
    return 0;
}