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
    long long ans = 0,tot;
    long long mod = 1e9+7;
    map<TreeNode*,long long> mp;
    
    long long max(long long a,long long b){
        if(a>=b) return a;
        return b;
    }
    
    long long totsum(TreeNode* root){
        if(root==NULL) return 0;
        if(mp.count(root)) return mp[root];
        long long left = totsum(root->left);
        long long right = totsum(root->right);
        return mp[root]=(left+right+root->val);
    }
    
    void solve(TreeNode* root){
        if(root==NULL) return;
        long left = totsum(root->left);
        long right = tot-left;
        if(left!=0) 
            ans = max(ans,left*right);
        right = totsum(root->right);
        left = tot-right;
        if(right!=0)
            ans = max(ans,left*right);
        solve(root->left);
        solve(root->right);
    }
    
    int maxProduct(TreeNode* root) {
        ans = 0;
        tot = totsum(root);
        solve(root);
        ans%=mod;
        return ans;
    }
};