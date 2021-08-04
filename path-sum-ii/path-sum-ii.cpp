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
    
    vector<vector<int>> ans;
    
    void solve(TreeNode* root,vector<int> cur,int targetSum){
        if(root==nullptr) return;
        if(root->val==targetSum && root->left==nullptr && root->right==nullptr){
            cur.push_back(root->val);
            ans.push_back(cur);
            return;
        }
        cur.push_back(root->val);
        solve(root->left,cur,targetSum-root->val);
        solve(root->right,cur,targetSum-root->val);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ans.clear();
        if(root==nullptr) return ans;
        vector<int> cur;
        solve(root,cur,targetSum);
        return ans;
    }
};