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
    
    TreeNode* solve(vector<int>& preorder,int l,int r){
        if(l>r) return nullptr;
        TreeNode* root = new TreeNode(preorder[l]);
        int ind = r+1;
        for(int i=l;i<=r;i++){
            if(preorder[i]>preorder[l]){
                ind = i;
                break;
            }
        }
        
        root->left = solve(preorder,l+1,ind-1);
        root->right = solve(preorder,ind,r);
        
        return root;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return solve(preorder,0,n-1);
    }
};