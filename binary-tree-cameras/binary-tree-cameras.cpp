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
    int cam = 0;
    
    int dfs(TreeNode* root){
        if(root==nullptr) return 1;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(left==0 || right==0){
            cam++;
            return 2;
        }
        else if(left==2 || right==2) return 1;
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        cam = 0;
        if(root==nullptr) return 0;
        int ans = dfs(root);
        if(ans==0) return cam+1;
        return cam;
    }
};