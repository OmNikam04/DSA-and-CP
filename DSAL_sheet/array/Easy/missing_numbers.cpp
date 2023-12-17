#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        vector<int>pf(nums.size()+1, 0);
        for(int it =0 ;  it<nums.size(); it++){
            pf[nums[it]] = 1;
        }
        for(auto it: pf)cout<<it<<" ";
        cout<<endl;

        for(int i = 0; i<pf.size(); i++){
            if(pf[i] == 0){
                return i;
            }
        }

        return -1;
    }
    int missingNumberOptimal(vector<int> &nums){
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            ans = ans ^ nums[i];
        }

        for(int i =1; i<=nums.size(); i++){
            ans = ans ^ i;
        }
        return ans;
    }
    int missingNumberOptimal(vector<int> &nums){
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            ans = ans ^ nums[i];
        }

        for(int i =1; i<=nums.size(); i++){
            ans = ans ^ i;
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
    cout<<s.missingNumberOptimal(nums);
    return 0;
}