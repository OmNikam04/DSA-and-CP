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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;

        map<int, map<int, multiset<int>>> mp;

        queue<pair<TreeNode*,pair<int,int>>> q;

        q.push({root, {0, 0}});

        while(!q.empty()){
            auto ptr = q.front();
            q.pop();

            TreeNode* node = ptr.first;
            int x = ptr.second.first;// vertical
            int y = ptr.second.second;// level

            mp[x][y].insert(node->val);// inserting to multiset

            if(node->left)
                q.push({node->left, {x-1, y+1}});
            if(node->right)
                q.push({node->right, {x+1, y+1}});
        }

        // printing map
        for(auto it: mp){
            vector<int>col;
            for(auto ele: it.second){
               col.insert(col.end(), ele.second.begin(), ele.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};