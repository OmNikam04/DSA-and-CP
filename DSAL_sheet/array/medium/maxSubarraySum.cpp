#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int mx = INT_MIN;
        int sum = 0;
        int start=0, end, arrayStart;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum == 0)
                start = i;
            if (sum < 0)
                sum = 0;
            if (sum > mx)
            {
                mx = max(mx, sum);
                arrayStart = start;
                end = i;
            }

        }
        cout<<"start: "<<start<<" end: "<<end<<endl;
        for(int i = arrayStart ; i<=end; i++)cout<<nums[i]<<" ";
        cout<<endl;
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
    cout << s.maxSubArray(nums);

    return 0;
}