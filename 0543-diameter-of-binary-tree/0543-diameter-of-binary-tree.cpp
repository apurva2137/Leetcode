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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxd = 0;
        diam(root , maxd);
        return maxd;
    }
    int diam(TreeNode* root , int& maxd){
        if(root == NULL) return 0;
        int lh = diam(root->left , maxd);
        int rh = diam(root->right , maxd);
        maxd = max(maxd , lh+rh);
        return 1 +max(lh , rh);
    }
};