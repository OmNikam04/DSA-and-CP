#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(vector<int> &stalls, int cows, int mid)
    {
        int cowsPlaced = 1;
        int lastPlacedCow = stalls[0];

        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - lastPlacedCow >= mid)
            {
                cowsPlaced++;
                lastPlacedCow = stalls[i];
            }
        }

        return cowsPlaced >= cows;
    }

    int aggressiveCows(vector<int> &stalls, int k)
    {
        sort(stalls.begin(), stalls.end());

        int low = 1;
        int high = stalls[stalls.size() - 1] - stalls[0];

        while (low <= high)
        {
            int mid = (low+high) / 2;

            if (check(stalls, k, mid))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return high;
    }
};
int main()
{
    int n;
    cin >> n;
    int cows;
    cin >> cows;
    vector<int> nums(n);
    for (auto &it : nums)
        cin >> it;
    Solution s;
    int ans = s.aggressiveCows(nums, cows);
    cout<<ans<<endl;
    return 0;
}