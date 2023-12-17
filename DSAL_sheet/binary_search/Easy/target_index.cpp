#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (high + low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
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
    cout << s.searchInsert(nums, target);
    return 0;
}