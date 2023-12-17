#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getDistinctCount(vector<int>&nums){
        set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        return st.size();
    }
    int countCompleteSubarrays(vector<int> &nums)
    {
        int ct = 0;
        int totalDistinct = getDistinctCount(nums);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                vector<int>temp;
                for(int k = i; k<=j; k++){
                    temp.push_back(nums[k]);
                }
                int tempCt = getDistinctCount(temp);
                if(totalDistinct == tempCt)ct++;
            }
            
        }
        return ct;
    }
    int subarray(vector<int> &nums)
    {
        int ct = 0;
        int totalDistinct = getDistinctCount(nums);
        for (int i = nums.size()-1; i >=0; i--)
        {
            for (int j =(nums.size()-i-1); j <= i; j++)
            {
                cout<<nums[j]<<" ";
            }cout<<endl;
            
        }
        return ct;
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
    cout<<endl<<s.subarray(nums);
    return 0;
}