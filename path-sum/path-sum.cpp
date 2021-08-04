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
    
    bool solve(TreeNode* root,int sum){
      //  if(root==NULL && sum!=0) return 0;
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL && sum==root->val) return 1;
        if(root->left== NULL && root->right==NULL && sum!=root->val) return 0;
       
        bool sum1=solve(root->left,sum-root->val);
        bool sum2=solve(root->right,sum-root->val);
        
        return sum1||sum2;
        
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL) return 0;
        
        return solve(root,sum);
    }
};