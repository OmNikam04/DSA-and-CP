#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int mx = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            int product = nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                mx = max(mx, product);
                product *= nums[j];
            }
            mx = max(mx, product);
        }
        return mx;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &it : nums)
        cin >> it;
    Solution s;
    cout << s.maxProduct(nums);
    return 0;
}