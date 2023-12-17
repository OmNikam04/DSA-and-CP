#include<bits/stdc++.h>
using namespace std;

void BS_on_rotatedArray(vector<int>&v, int x){
    int lo = 0, hi = v.size()-1;
    int mid;
    while(hi - lo> 1){
        mid = (hi + lo)/2;

        if(v[mid] == x){
            // ** This condition becomes necessary
            // ** as we are using hi - lo > 1 condition for 
            // ** Loop termination
            cout<<x<<" is at index: "<<mid<<endl;
            return;
        }
        else if(v[mid] > v[0])
        {
            // ** We are in region 1
            if(x < v[0])lo = mid+ 1;
            else if(x < v[mid]) hi = mid -1;
            else lo = mid + 1;
        }else{
            // **We are in region 2
            if(x >= v[0]) hi = mid - 1;
            else if(x < v[mid]) hi = mid -1;
            else lo = mid + 1;
        }
    }
    if(v[lo] == x){
        cout<<v[lo]<<" is at index: "<<lo<<endl;
    }
    else if(v[hi] == x){
        cout<<v[hi]<<" is at index: "<<hi<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
}


int main()
{
    int n,to_find;
    cin>>n>>to_find;
    vector<int>v;
    for(int i= 0; i<n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    BS_on_rotatedArray(v,to_find);
    return 0;
}