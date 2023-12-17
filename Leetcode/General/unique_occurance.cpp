#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        for(auto it:arr){
            m[it]++;
        }    
        
        unordered_set<int>st;
        for(auto &it:m){
            if(st.find(it.second) != st.end()){
                return false;
            }
            st.insert(it.second);
        }
        return true;
    }

};
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0; i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    } 
    Solution s;
    cout<<s.uniqueOccurrences(v);
    return 0;
}