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

class Solution {
public:
    int findMaxPath(TreeNode* root, int &ans){
        if(root == nullptr)
            return 0;
        
        int ls = max(0, findMaxPath(root->left, ans));
        int rs = max(0, findMaxPath(root->right, ans));

        ans = max(ans, ls +rs + root->val);

        return (root->val) + max(ls, rs);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findMaxPath(root, ans);
        return ans;
    }
};