#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, target;
    cin >> n >> target;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    bool ans =false;

    int right = 0;
    int left = n-1;
    while (right<n && left>=0)
    {
        if(a[right][left] == target){
            ans = true;
        }if(a[right][left] > target){
            left--;
        }else{
            right++;
        }
    }
    
    if (ans)
    {
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;
}