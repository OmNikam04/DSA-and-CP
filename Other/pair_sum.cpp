#include <bits/stdc++.h>
using namespace std;

// This will takes O(N^2) time complexity
// int main(){
//     int n, target;
//     cin>>n>>target;
//     int a[n];
//     for(int i = 0; i<n; i++)cin>>a[i]; // input array
//     bool ans = false;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             if(a[i]+a[j]== target){
//                 ans = true;
//                 break;
//             }
//         }
//     }
//     if(ans)cout<<"Yes"<<endl;
//     else cout<<"No"<<endl;
// }

// This will take O(N) time complexity
int main()
{
    int n, target;
    cin >> n >> target;
    int a[n];
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    bool ans = false;
    for(int i = 0; i<n; i++){
        if(s.find(target - a[i]) != s.end()){
            ans = true;
        }
    }
    if(ans)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}