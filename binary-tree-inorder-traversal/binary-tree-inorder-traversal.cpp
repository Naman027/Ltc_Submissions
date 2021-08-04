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
    vector<int> inorderTraversal(TreeNode* root) {
        // Morris Traversal
        if(root==nullptr) return {};
        vector<int> ans;
        TreeNode* cur = root;
        while(cur!=nullptr){
            if(cur->left==nullptr){
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* pred = cur->left;
                while(pred->right!= cur && pred->right!=NULL) pred = pred->right;
                
                if(pred->right==NULL){
                    pred->right = cur;
                    cur = cur->left;
                }
                else{
                    pred->right = NULL;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};