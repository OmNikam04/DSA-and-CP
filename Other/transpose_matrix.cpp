// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int a[n][n]= {0};
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = i; j <=n; j++)
//         {
//             if(i!=j){
//                 swap(a[i][j],a[j][i]);
//             }
//         }
//     }
//     // Printing array
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cout<<a[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n][n];
    // Taking input
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    // Performing inverse operation
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++) //Always starts from i so we only swap upper diagonal
        {
                swap(a[i][j], a[j][i]);
        }
    }
    // Printing array
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}