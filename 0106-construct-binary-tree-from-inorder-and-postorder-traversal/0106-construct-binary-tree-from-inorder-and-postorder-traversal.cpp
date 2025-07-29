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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i < inorder.size() ; i++) mp[inorder[i]] = i;

        int n = inorder.size();
        int posi = n - 1;

        return build(inorder , postorder , 0 , n-1 , posi, mp);
    }
    TreeNode* build(vector<int>& in , vector<int>& post , int ins , int ine , int& posi ,unordered_map<int,int>& mp ){

        if(ins > ine) return NULL;

        TreeNode* node = new TreeNode(post[posi]);
        posi--;

        int idx = mp[node->val];

        node->right = build(in , post , idx + 1, ine , posi, mp);
        node->left = build(in , post , ins , idx - 1 , posi, mp);

        return node;
    }
};