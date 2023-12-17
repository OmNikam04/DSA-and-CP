#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    // reverse(v.begin(),v.end());
    // for(auto it: v){
    //     cout<<it<<" ";
    // }
    cout<<endl;
    cout << *min_element(v.begin(), v.end()) << endl;
    cout << *max_element(v.begin(), v.end()) << endl;
    cout<< accumulate(v.begin(),v.end(),0)<<endl;
    cout<<count(v.begin(),v.end(),4)<<endl;
    auto it = find(v.begin(),v.end(),10);
    if(it!=v.end()){
        cout<<*it<<endl;
    }else{
        cout<<"Not found"<<endl;
    }
    string s = "OmNikam";
    reverse(s.begin(),s.end());
    cout <<s<<endl;

    return 0;
}