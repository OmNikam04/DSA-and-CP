#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string>res;
        int pos = 0;
        for(auto it: words){
            string token = "";
            while((pos = it.find(separator)) != string::npos){
                token = it.substr(0, pos);
                res.push_back(token);
                it.erase(0, pos);
            }
        }   
        return res;
    }
};

int main()
{
    vector<string> words;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        words.push_back(s);
    }
    char separator;
    cin>>separator;
    Solution s;
    vector<string> ans = s.splitWordsBySeparator(words, separator);
    // for(auto it: ans){
    //     cout<<it<<" ";
    // }cout<<endl;
    return 0;
}