/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        unordered_map<int ,int> mp;
        queue<pair<TreeNode*,int>> q;
        vector<int> ans;

        q.push({root , 0});

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            mp[level] = node->val;
            
            if(node->left) q.push({node->left , level + 1});
            if(node->right) q.push({node->right , level + 1});
        }
        int i = 0;
        while (mp.find(i) != mp.end()) {
            ans.push_back(mp[i]);
            i++;
        }
        return ans;
    }
};