class Solution {
public:
    int ans = 0;

    int solve(TreeNode* root){
        if(root==nullptr) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        ans = max(ans,left+right);
        //cout << root->val << " " << ans << endl;
        return 1+max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};