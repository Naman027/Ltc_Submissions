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
    int maxlev = 0;
    TreeNode* ans;
    
    int solve(TreeNode* root,int lev){
        if(root==nullptr) return lev;
        int left = solve(root->left,lev+1);
        int right = solve(root->right,lev+1);
        
        if(left==right){
            maxlev = max(maxlev,left);
            if(maxlev==left){
                ans = root;
            }
        }
        return max(left,right);
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root==nullptr) return nullptr;
        maxlev = 0;
        ans = nullptr;
        int lev = solve(root,0);
        return ans;
        
    }
};