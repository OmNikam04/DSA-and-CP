#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        // We are taking n+1 to handle caes for 1 based indexing
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ultp_u = findUParent(u);
        int ultp_v = findUParent(v);

        // if both nodes have same parent then no need to do anything
        if(ultp_u == ultp_v)return;

        if(rank[ultp_u] < rank[ultp_v]){
            parent[ultp_u] = ultp_v;
        }
        else if(rank[ultp_v] < rank[ultp_u]){
            parent[ultp_v] = ultp_u;
        }
        else{
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // check if 1 and 7 belongs to same component
    if(ds.findUParent(1) == ds.findUParent(7))
        cout<<"YES\n";
    else cout<<"NO\n";

    ds.unionByRank(3, 7);
    if(ds.findUParent(1) == ds.findUParent(7))
        cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}