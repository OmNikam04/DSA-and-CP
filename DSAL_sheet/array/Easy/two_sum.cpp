#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size()-1;
        sort(nums.begin(), nums.end());
        while(left<right){
            if(nums[left] + nums[right] == target){
                return {nums[left], nums[right]};
            }
            else if(nums[left]+ nums[right] > target){
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
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> nums(n);
    for (auto &it : nums)
        cin >> it;
    Solution s;
    vector<int>ans = s.twoSum(nums, target);
    for(auto &it: ans)cout<<it<<" ";
    cout<<endl;
    return 0;
}