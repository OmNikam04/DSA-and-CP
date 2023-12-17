#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>&v, int x){
    if(v.size()==0 || v[v.size()-1] <=x)
    {
        v.push_back(x);
        return;
    }

    int val = v[v.size()-1];
    v.pop_back();
    insert(v, x);
    v.push_back(val);
}

void my_sort(vector<int>&v){
    // base condition
    // array with size 1 is already sorted
    if(v.size()==1)
        return;
    
    // take the last element
    int val = v[v.size()-1];
    v.pop_back();
    my_sort(v);
    insert(v, val);
}


void my_sort2(vector<int>&v, int n, int i){
    if(i == n-1)
        return;
    
    my_sort2(v, n, i+=1);

    if(v[i] < v[i-1])
        swap(v[i], v[i-1]);
    
    my_sort2(v, n, i);
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n,0);
    for(auto &it: v)cin>>it;
    // my_sort(v);
    my_sort2(v, v.size(), 0);   
    for(auto it: v)cout<<it<<" ";
    cout<<endl;
    return 0;
}