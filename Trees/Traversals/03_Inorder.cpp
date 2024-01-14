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

class Solution
{
public:
    void inorderRecursive(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;

        inorderRecursive(root->left, ans);
        ans.push_back(root->val);
        inorderRecursive(root->right, ans);
    }

    void inorderInterative(TreeNode *node, vector<int> &ans)
    {
        stack<TreeNode *> st;
        while (true)
        {
            if (node != nullptr)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                // node is at nullptr
                if (st.empty())
                    break;
                node = st.top();
                ans.push_back(node->val);
                st.pop();
                node = node->right;
            }
        }
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;

        if (root == nullptr)
            return ans;

        inorderInterative(root, ans);

        return ans;
    }
};