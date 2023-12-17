#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        vector<int>temp;
        for(auto it: mp){
            if(it.second > (nums.size()/3)){
                temp.push_back(it.first);
            }
        }

        return temp;
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
    vector<int>ans = s.majorityElement(nums);
    for(auto it: ans)cout<<it<<" ";
    cout<<endl;
    return 0;
}