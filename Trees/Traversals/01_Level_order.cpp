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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        TreeNode *node = root;
        q.push(node);

        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        while (!q.empty())
        {
            // remove node from queue
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *nt = q.front();
                q.pop();

                if (nt->left != nullptr)
                    q.push(nt->left);
                if (nt->right != nullptr)
                    q.push(nt->right);
                level.push_back(nt->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};