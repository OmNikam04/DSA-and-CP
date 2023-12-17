#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void letterCombinations(string digits)
    {
        unordered_map<char, string>mp;
        mp.emplace('2',"abc");
        mp.emplace('3',"def");
        mp.emplace('4',"ghi");
        mp.emplace('5',"jkl");
        mp.emplace('6',"mno");
        mp.emplace('7',"pqrs");
        mp.emplace('8',"tuv");
        mp.emplace('9',"wxyz");
    }
};
int main()
{
    string digits;
    cin>>digits;
    Solution s;
    s.letterCombinations(digits);
    // vector<string> ans = s.letterCombinations(digits);
    // for(auto it: ans)cout<<it<<" ";
    // cout<<endl;
    return 0;
}