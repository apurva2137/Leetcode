class Solution {
public:
    int dfs(TreeNode* root , int maxval){
        if(root == NULL) return 0;
        int count = 0;

        if(root->val >= maxval){
            maxval = root->val;
            count = 1;
        }

        count += dfs(root->left , maxval);
        count += dfs(root->right , maxval);
        return count;
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return dfs(root , root->val);
    }
};