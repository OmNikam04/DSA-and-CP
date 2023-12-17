#include<bits/stdc++.h>
using namespace std;

int getPartition(vector<int>&v, int low, int high){
    int i = low, j = high;
    int pivot = v[low];
    while(i<j){
        while (v[i]<=pivot && i<=high-1)
            i++;
        while(v[j]>pivot && j>=low+1)
            j--;
        if(i<j)swap(v[i],v[j]);
    }
    swap(v[low],v[j]);
    return j;
}

void qs(vector<int>&v, int low, int high){
    if(low<high){
        int partition = getPartition(v, low, high);
        qs(v, low, partition -1);
        qs(v, partition+1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    qs(v, 0, n - 1);
    for(auto it: v){
        cout<<it<<" ";
    }cout<<endl;
    return 0;
}