#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (!ans.empty() && end <= ans.back()[1])
                continue;

            for (int j = i + 1; j < n; ++j)
            {
                if (intervals[j][0] <= end)
                    end = max(end, intervals[j][1]);
                else
                    break;
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> nums;
    for (int i = 0; i < n; ++i)
    {
        vector<int> temp;
        for (int j = 0; j < 2; ++j)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        nums.push_back(temp);
    }
    Solution s;
    vector<vector<int>> ans = s.merge(nums);
    for (auto it : ans)
    {
        for (auto ele : it)
            cout << ele << " ";
        cout << endl;
    }
    return 0;
}