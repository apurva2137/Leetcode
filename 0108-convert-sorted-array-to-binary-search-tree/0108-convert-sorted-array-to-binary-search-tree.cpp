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
private:
    TreeNode* createTree(vector<int>& nums, int left , int right){
        if(left > right) return nullptr;
        int mid = left + ((right - left)/2);
        int midval = nums[mid];
        TreeNode* root = new TreeNode(midval);
        root->left = createTree(nums , left , mid -1);
        root->right = createTree(nums , mid+1 , right);
        
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createTree(nums,0,nums.size()-1);
    }
};