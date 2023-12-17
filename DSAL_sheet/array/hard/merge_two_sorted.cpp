#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> temp;
        int i = 0, j = 0;

        while (i <= m - 1 && j <= n - 1)
        {
            if (nums1[i] < nums2[j])
            {
                temp.push_back(nums1[i]);
                i++;
            }
            else
            {
                temp.push_back(nums2[j]);
                j++;
            }
        }

        while (i <= m - 1)
        {
            temp.push_back(nums1[i]);
            i++;
        }

        while (j <= n - 1)
        {
            temp.push_back(nums2[j]);
            j++;
        }
        nums1.clear();
        for (int k = 0; k < m+n; k++)
            nums1.push_back(temp[k]);
    }
};
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> a(n+m);
    vector<int> b(m);
    for (auto &it : a)
        cin >> it;
    for (auto &it : b)
        cin >> it;
    Solution s;
    s.merge(a, m, b, n);
    return 0;
}