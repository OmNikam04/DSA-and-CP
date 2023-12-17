#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;

        for(int i =0; i<n; i++){
            // avoid duplicate nums[i]
            if(i!=0 && nums[i] == nums[i-1])continue;

            for(int j = i+1; j<n; j++){
                // avoid duplicate nums[j]
                if(j > i+1 && nums[j] == nums[j-1])continue;

                int k = j+1; 
                int m = n-1; // points to last
                while(k<m){
                    int sum = nums[i] + nums[j] + nums[k] + nums[m];
                    if(sum > target)
                        m--;
                    else if(sum < target)
                        k++;
                    else{
                        // sum == target
                        vector<int>temp = {nums[i], nums[j], nums[k], nums[m]};
                        ans.push_back(temp);
                        k++;
                        m--;

                        while(k<m && nums[k] == nums[k-1]) k++;
                        while(k<m && nums[m] == nums[m+1]) m--;
                    }
                }
            }
        }

        return ans;
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
    vector<vector<int>> ans = s.fourSum(nums, target);
    for (auto ele : ans)
    {
        for (auto it : ele)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}