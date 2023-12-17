#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long minimumPossibleSum(int n, int target)
    {
        unordered_set<int> nums;
        long long i = 1;
        while (nums.size() < n)
        {
            if (nums.find(target - i) != nums.end())
            {
                i++;
                continue;
            }
            else
            {
                nums.insert(i);
                i++;
            }
        }
        long long sum = 0;
        for (auto it : nums)
            sum += it;
        return sum;
    }
};
int main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;

    Solution s;
    cout << s.minimumPossibleSum(n, t);
    return 0;
}