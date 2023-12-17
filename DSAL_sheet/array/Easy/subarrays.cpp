#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void all_subarray(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        int mx = INT_MIN;
        for(int i = 2; i<=4; i++){
            sum ^= nums[i];
        }  
        cout<<sum<<endl;
    }
    vector<int> max_subarray_sum(vector<int>&nums, int k){
        int i = 0, j= 0;
        int n = nums.size();
        vector<int>temp;
        vector<int>ans;
        while(j<n){
            if(nums[j]<0)
                temp.push_back(nums[j]);
            int winSize = j - i +1;
            if(winSize < k)j++;

            else if(winSize == k){
                // check if temp is empty
                if(temp.size() == 0) ans.push_back(0);
                else{
                    ans.push_back(temp.front());
                    // remove temp 1st element if it is negative
                    if(nums[i] < 0)
                        temp.erase(temp.begin());
                }
                i++; j++;
            }
        }   

        return ans;
    }
};
int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    int k; cin>>k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    Solution s;
    // s.all_subarray(nums);
    vector<int> ans = s.max_subarray_sum(nums, k);
    for(auto it: ans)cout<<it<<" ";
    cout<<endl;

    return 0;
}