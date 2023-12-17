#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target)
    {
        int ct = 0;
        for(auto it: hours){
            if(it>=target){
                ct++;
            }
        }
        return ct;
    }
};
int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    int t;
    cin >> t;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution s;
    cout<<s.numberOfEmployeesWhoMetTarget(nums, t);
    return 0;
}