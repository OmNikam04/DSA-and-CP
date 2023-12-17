#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void print_stack(stack<char> &st, string &ans)
    {
        if (st.empty())
            return;
        char ch = st.top();
        st.pop();
        print_stack(st, ans);
        ans.push_back(ch);
        st.push(ch);
    }
    string removeKdigits(string num, int k)
    {
        stack<char> st;
        for (int i = 0; i<num.size(); i++)
        { 
            while (k > 0 && !st.empty() && st.top() > (num[i]))
            {
                cout <<"s[i]: " << num[i]<<"st.top() :" <<st.top();
                cout << k << endl;
                st.pop();
                k--;
            }
                st.push(num[i]);
        }
        while(k>0 && !st.empty()){
            k--;
            st.pop();
        }
        string ans = "";
        print_stack(st, ans);
        int a = stoi(ans);
        ans = to_string(a);
        return ans;
    }
};
int main()
{
    string str;
    cin >> str;
    int k;
    cin >> k;
    Solution s;
    cout<< s.removeKdigits(str, k);
    return 0;
}