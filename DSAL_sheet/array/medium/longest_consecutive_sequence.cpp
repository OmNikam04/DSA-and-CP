#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int better(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ct = 0;
        int mx = 1;
        int lastSmaller = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] - 1 == lastSmaller)
            {
                ct += 1;
                lastSmaller = nums[i];
            }
            else if (nums[i] != lastSmaller)
            {
                ct = 1;
                lastSmaller = nums[i];
            }
            mx = max(mx, ct);
        }
        return mx;
    }

    int longestConsecutive(vector<int> &nums)
    {
        set<int> st;
        for (auto it : nums)
        {
            st.insert(it);
        }
        int mx = INT_MIN;
        for (auto it : st)
        {
            int ct = 1;
            int temp = it;
            if (st.find(temp - 1) == st.end())
            {
                while (st.find(temp + 1) != st.end())
                {
                    temp = temp +1;
                    ct++;
                }
                mx = max(mx, ct);
            }
        }
        return mx;
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
    cout << s.longestConsecutive(nums);
    return 0;
}