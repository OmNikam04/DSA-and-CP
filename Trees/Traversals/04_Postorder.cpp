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
    void postOrderRecursive(TreeNode* root, vector<int>&ans){
        if(root == nullptr) return;

        postOrderRecursive(root->left, ans);
        postOrderRecursive(root->right, ans);
        ans.push_back(root->val);
    }
    // this approach uses 2 stacks 
    void postOrderIterative(TreeNode* root, vector<int>&ans){
        stack<TreeNode*>s1,s2;
        TreeNode* node = root;
        s1.push(node);
        while(!s1.empty()){
            TreeNode* topSt1 = s1.top();
            s2.push(topSt1);
            s1.pop();
            if(topSt1->left != nullptr){
                s1.push(topSt1->left);
            }
            if(topSt1->right != nullptr){
                s1.push(topSt1->right);
            }
        }

        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr) return ans;

        postOrderIterative(root, ans);

        return ans;
    }
};