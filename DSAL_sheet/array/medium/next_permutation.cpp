#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void next_permute(vector<int> &nums)
    {
        int n = nums.size();
        int ind = -1;
        for(int i = n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }

        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }


        // swapping ind with element just greater than nums[ind]
        for(int i = n-1; i>= ind+1; i--){
            if(nums[ind]<nums[i]){
                swap(nums[ind], nums[i]);
                break;
            }
        }

        reverse(nums.begin() + ind+1, nums.end());

    }
};
int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    Solution s;
    s.next_permute(nums);

    for(auto it: nums)cout<<it<<" ";
    cout<<endl;
    return 0;
}