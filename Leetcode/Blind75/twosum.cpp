#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        map<int ,int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]] = i;
        }
        for(auto &it: m){
            auto tofind = m.find(target - it.first);
            if(tofind != m.end() && *tofind != it)
                ans.push_back((*tofind).second);
        }
        sort(ans.begin(), ans.end());   // O(n*logn)
        return ans;
    }

    vector <int> twoSumOptimized(vector<int> & nums, int target){
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size()-1;

        while(left<right){
            int sum = nums[left]+nums[right] ;
            if(sum == target){
                return {left, right};
            }
            else if(sum > target){
                right--;
            }
            else{
                left++;
            }
        }

        return {-1, -1};
    }
};

int main()
{
    vector<int> input;
    int n; cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        input.push_back(x);
    }
    int target; cin>>target;
    Solution obj;
    vector<int>ans = obj.twoSumOptimized(input, target);
    for(auto num: ans){
        cout<<num<<" ";
    }cout<<endl;

    return 0;
}