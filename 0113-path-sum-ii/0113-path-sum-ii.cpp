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
    void path(TreeNode* root, int target , vector<int>& v,vector<vector<int>>& ans){
        if(root == NULL) return;
        v.push_back(root->val);
        if(!root->left && !root->right){
            if(root->val == target){
                ans.push_back(v);
            }
            v.pop_back();
            return;
        }
        
        path(root->left , target - root->val , v , ans);
        path(root->right , target - root->val , v , ans);
        v.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        if(root == NULL) return ans;
        path(root , targetSum , v ,ans );
        return ans;
    }
};