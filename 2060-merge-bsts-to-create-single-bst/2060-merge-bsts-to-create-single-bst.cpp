class Solution {
public:
bool check(TreeNode* root,int lb,int ub){
if(root==NULL)return true;
if(root->val<=lb||root->val>=ub)return false;

    bool left=check(root->left,lb,root->val);
    bool right=check(root->right,root->val,ub);
    return left&right;
}
TreeNode* canMerge(vector<TreeNode*>& trees) {
 unordered_set<int>st;
    unordered_map<int,TreeNode*>hash;
    unordered_set<TreeNode*>temp;
    for(auto it:trees){
        hash[it->val]=it;
        temp.insert(it);
        if(it->left)st.insert(it->left->val);
         if(it->right)st.insert(it->right->val);
    }
    TreeNode* root=NULL;
    int cnt=0;
    for(auto it:trees){
       if(st.find(it->val)==st.end()){
           cnt++;
           root=it;
           if(cnt>1)return {};
       } 
    }
    temp.erase(root);
    queue<TreeNode*>que;
    if(root==NULL)return {};
    que.push(root);
    while(que.size()){
        int size=que.size();
        while(size--){
            TreeNode* node=que.front();
            que.pop();
            if(node->left==NULL&&node->right==NULL){
               
                if(temp.find(hash[node->val])!=temp.end()){
                    node->left=hash[node->val]->left;
                    node->right=hash[node->val]->right;
                    temp.erase(hash[node->val]);
                }
            }
            if(node->left)que.push(node->left);
            if(node->right)que.push(node->right);
        }
    }
    if(temp.size())return {};
      if(check(root,INT_MIN,INT_MAX))return root;
      return {};
}
};