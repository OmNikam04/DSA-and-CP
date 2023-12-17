#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int isPossible(int *arr, int n, int students, int pages){
        int pageCt = 0;
        int stct = 1;
        
        for(int i =0 ;i<n; i++){
            if(pageCt + arr[i] > pages){
                pageCt = arr[i];
                stct ++;
            }
            else{
                pageCt += arr[i];
            }
        }
        
        
        return stct;
    }
    int findPages(int arr[], int N, int M)
    {
        // sort(arr, arr + N);
        int low = *max_element(arr, arr + N);
        int high = accumulate(arr, arr + N, 0);
        cout<<"low: "<<low<<" High: "<<high<<endl;
        // while(low<=high){
        //     int mid = (low+high)/2;
        //     if(isPossible(arr, N, M, mid) > M)
        //         low = mid + 1;
        //     else
        //         high = mid - 1;
        // }
        // return low;
        int ans = -1;
        for (int i = low; i <= high; i++)
        {
            if (isPossible(arr, N, M, i) == M)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution s;
    cout<<s.findPages(arr, n, m);

    return 0;
}