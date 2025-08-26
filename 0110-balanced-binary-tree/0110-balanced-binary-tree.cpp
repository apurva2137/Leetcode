class Solution {
public:
    bool isBalanced(TreeNode* root){
        return bal(root) != -1;
    }
    int bal(TreeNode* root){
        if(root == NULL) return 0;
        int lh = bal(root->left);
        if(lh == -1) return -1;
        int rh = bal(root->right);
        if(rh == -1) return -1;
        if(abs(lh-rh) > 1) return -1;
        return 1 + max(lh , rh);
    }
};