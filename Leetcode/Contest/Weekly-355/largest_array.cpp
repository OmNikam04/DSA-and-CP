#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getIndOfMaxElement(vector<int> &v)
    {
        int mx_ele = v[0];
        int ind = 0;
        for (auto i = 0; i < v.size(); i++)
        {
            if (v[i] > mx_ele)
            {
                ind = i;
                mx_ele = v[i];
            }
        }
        return ind;
    }
    void merge(vector<int> &nums, int ind)
    {
        if(nums[ind]<=nums[ind+1]){
            nums[ind] = nums[ind] + nums[ind + 1];
        }
        for (int i = ind + 1; i < nums.size() - 1; i++)
        {
            nums[i] = nums[i + 1];
        }
        nums.resize(nums.size() - 1);
    }
    long long maxArrayValue(vector<int> &nums)
    {
        while (nums.size()>1)
        {
            vector<int> hsh;
            cout<<"Hash: "<<endl;
            for (int i = 0; i < nums.size()-1; i++)
            {
                if (nums[i] <= nums[i + 1])
                {
                    hsh.push_back(nums[i] + nums[i + 1]);
                }else hsh.push_back(nums[i]);
                cout<<hsh[i]<<" ";
            }cout<<endl;
            int ind = getIndOfMaxElement(hsh);
            cout<<"ind: "<<ind<<endl;
            merge(nums, ind);
            cout<<"Nums: "<<endl;
            for(auto it: nums)cout<<it<<" ";
            cout<<endl;
        }
    cout<<" OUtput: "<<endl;
        return *max_element(nums.begin(), nums.end());
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    Solution s;
    cout<<s.maxArrayValue(v);

    return 0;
}