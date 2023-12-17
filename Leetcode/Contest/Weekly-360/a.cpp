#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int furthestDistanceFromOrigin(string moves)
    {
        if(moves.find('R') == string::npos && moves.find('L') == string::npos){
            return moves.length();
        }
        int countL = count(moves.begin(), moves.end(), 'L');
        int countR = count(moves.begin(), moves.end(), 'R');
        int coutU = count(moves.begin(), moves.end(), '_');

        int x = abs(countL - countR);
        return coutU + x;        
    }
};
int main()
{
    // int n;cin>>n;
    // vector<int>nums(n);
    // for(auto& it:nums)cin>>it;
    string moves;
    cin >> moves;
    Solution s;
    cout<<s.furthestDistanceFromOrigin(moves);
    return 0;
}