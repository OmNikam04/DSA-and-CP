#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> temp1, temp2, ans;

        for (auto i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                // even number
                temp1.push_back(nums[i]);
            }
            else
            {
                temp2.push_back(nums[i]);
            }
        }
        for (int i = 0; i < nums.size()/2; i++)
        {
            if (temp1.size() != 0)
            {
                ans.push_back(temp1[i]);
            }
            if (temp2.size() != 0)
            {
                ans.push_back(temp2[i]);
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
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    Solution s;
    vector<int>ans = s.rearrangeArray(nums);
    for(auto it: ans)cout<<it<<" ";
    cout<<endl;

    return 0;
}