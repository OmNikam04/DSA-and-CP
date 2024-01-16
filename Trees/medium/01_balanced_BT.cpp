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

// sol 1: For each node check its height of leftsubtree and rightsubtree
// if difference is > 1 then return false
// TC: O(n)  * O(n)
class Solution {
public:
    int findHeight(TreeNode* root){
        if(root == nullptr)
            return 0;
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);

        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;

        int lh = findHeight(root->left);
        int rh = findHeight(root->right);

        if(abs(lh - rh) > 1)
            return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(!left || !right)
            return false;
        return true; 
    }
};

// Sol 2: if tree balanced return its height else return -1
class Solution {
public:
    int check(TreeNode* root){
        if(!root)
            return 0;
        int lh = check(root->left);
        if(lh == -1)
            return -1;
        int rh = check(root->right);
        if(rh == -1)
            return -1;

        if(abs(lh - rh) > 1)
            return -1;

        return max(rh, lh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};