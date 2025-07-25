class Solution {
public:
    int path(TreeNode* root, long long target) {
        if (root == NULL) return 0;
        int count = 0;
        if (root->val == target) count++;

        count += path(root->left, target - root->val);
        count += path(root->right, target - root->val);

        return count;
    }

    int pathSum(TreeNode* root, int target) {
        if (root == NULL) return 0;

        int count = path(root, target);
        count += pathSum(root->left, target);
        count += pathSum(root->right, target);

        return count;
    }
};
