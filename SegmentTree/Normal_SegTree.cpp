#include<bits/stdc++.h>
using namespace std;

class SegTree {
public: 
    int len;
    vector<int> t;

    SegTree() {};
    SegTree(int l) {
        this->len = l;
        t.resize(4 * len, 0); // Initialize with 0
    }

    // Build segment Tree
    // v is current vertex
    // tl -> tree left, tr -> tree right
    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }

    // Query the sum in range [l, r] (inclusive)
    int query(int v, int tl, int tr, int l, int r) {
        // No overlap
        if (tr < l || tl > r)
            return 0;
        
        // Full overlap
        if (tl >= l && tr <= r) {
            return t[v];
        }

        // Partial overlap
        int tm = (tl + tr) / 2;
        int left = query(v * 2, tl, tm, l, r);
        int right = query(v * 2 + 1, tm + 1, tr, l, r);
        return left + right;
    }

    // Point update (updating only a single value)
    // update at index ind to a value val
    void update(int v, int tl, int tr, int ind, int val) {
        // Reached the leaf node
        if (tl == ind && tr == ind) {
            t[v] = val;
            return;
        }

        int tm = (tl + tr) / 2;
        if (ind <= tm) {
            update(v * 2, tl, tm, ind, val);
        } else {
            update(v * 2 + 1, tm + 1, tr, ind, val);
        }
        t[v] = t[2 * v] + t[2 * v + 1];
    }

    // Override functions
    void build(vector<int>& a) {
        build(a, 1, 0, len - 1);    
    }

    int query(int l, int r) {
        return query(1, 0, len - 1, l, r);
    }

    void update(int ind, int val) {
        update(1, 0, len - 1, ind, val);
    }
};

int main() {
    int n = 8;
    vector<int> a = {1, 2, 1, 4, 2, 3, 1, 1};

    SegTree segTree(n);
    segTree.build(a);

    // Build - View Build Data
    for (int i = 0; i < n; i++) {
        cout << segTree.query(i, i) << " ";
    }
    cout << endl;

    // Query - Range Query
    int sum = segTree.query(1, 5);
    cout << "Sum for range id = 1 to id = 5 is: " << sum << endl;

    // Update - Point Update
    segTree.update(2, 10); // at id=2, make the value = 10
    sum = segTree.query(1, 5);
    cout << "New Sum for range id = 1 to id = 5 is: " << sum << endl;


    /*
        Output: 
        1 2 1 4 2 3 1 1 
        Sum for range id = 1 to id = 5 is: 12
        New Sum for range id = 1 to id = 5 is: 21
    */

    return 0;
}
