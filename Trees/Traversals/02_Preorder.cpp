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
    void preorder(TreeNode* root, vector<int>& ans){
        if(root == nullptr) return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    void preorderIterative(TreeNode* root, vector<int> &ans){
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp = st.top();
            ans.push_back(temp->val);
            st.pop();

            if(temp->right != nullptr)
                st.push(temp->right);
            if(temp->left != nullptr)
                st.push(temp->left);                
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr) return ans;

        preorderIterative(root, ans);

        return ans;
    }
};

