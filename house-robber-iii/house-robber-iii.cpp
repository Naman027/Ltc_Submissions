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
    
    map<TreeNode*,int> mp;
    
    int rob(TreeNode* root) {
        if(root==nullptr) return 0;
        // considering root as an ans
        if(mp.count(root)) return mp[root];
        int ans = root->val;
        if(root->left){
            ans += rob(root->left->left)+rob(root->left->right);
        }
        
        if(root->right){
            ans += rob(root->right->left) + rob(root->right->right);
        }
        
        ans = max(ans,rob(root->left)+rob(root->right));
        mp[root] = ans;
        return ans;
        
    }
};