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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);

        bool flag = true;

        while(!q.empty()){
            int size =  q.size();
            vector<int>level(size);
            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                
                // logic for zigzag
                int ind = flag ? i : size-i-1;
                level[ind] = node->val;

                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
            }
            flag = !flag;
            ans.push_back(level);
        }

        return ans;
    }
};