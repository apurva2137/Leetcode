class Solution {
    bool pathsum(TreeNode* root , int k){
        if(root == NULL) return false;
        
        if(!root->left && !root->right){
           return k == root->val;
        }
        bool isleft = pathsum(root->left , k- root->val);
        bool isright = pathsum(root->right , k - root->val);
        return isleft || isright ;
    }
public:
    bool hasPathSum(TreeNode* root, int k) {
        return pathsum(root , k );
    }
};