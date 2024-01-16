#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// sol 1: O(n*n)
// At each node we are checking sum of its left height and right height 
class Solution {
public:
    int findHeight(TreeNode* root){
        if(!root)
            return 0;
        
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);

        return max(lh, rh) + 1;
    }

    void myfunc(TreeNode* root, int &mx){
        if(root == nullptr) return;  

        int lh = findHeight(root->left);
        int rh = findHeight(root->right);

        mx = max(lh + rh, mx);

        myfunc(root->left, mx);
        myfunc(root->right, mx);
    }
    int diameterOfBinaryTree(TreeNode* root) {  
        int mx = 0;
        myfunc(root, mx);
        return mx;
    }
};

// Sol 2: O(N)
// no need to separately check each node 
// check the max sum of each node's left and right height 
// at the time of calculating its heigh
class Solution {
public:
    int findHeight(TreeNode* root, int &mx){
        if(!root)
            return 0;
        
        int lh = findHeight(root->left, mx);
        int rh = findHeight(root->right, mx);

        mx = max(mx, lh+rh);

        return max(lh, rh) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {  
        int mx = 0;
        findHeight(root, mx);
        return mx;
    }
};