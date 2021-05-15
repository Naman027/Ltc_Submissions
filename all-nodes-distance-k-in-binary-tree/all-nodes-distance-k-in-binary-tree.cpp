/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*,TreeNode*> par;
    
    void parent(TreeNode* root){
        if(root==nullptr) return;
        if(root->left) par[root->left] = root, parent(root->left);
        if(root->right) par[root->right] = root, parent(root->right);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent(root);
        par[root] = nullptr;
        queue<TreeNode*> q;
        q.push(target);
        vector<bool> vis(502,0);
        int d = 0;
        vector<int> ans;
        while(!q.empty()){
            int len  = q.size();
            while(len--){
                TreeNode* cur = q.front();
                q.pop();
                if(d==k) ans.push_back(cur->val);
                vis[cur->val] = 1;
                if(cur->left){
                    if(!vis[cur->left->val]) q.push(cur->left);
                }
                
                if(cur->right){
                    if(!vis[cur->right->val]) q.push(cur->right);
                }
                
                TreeNode* pa = par[cur];
                if(pa!=nullptr && !vis[pa->val]){
                    q.push(pa);
                }
                else if(pa==nullptr){
                    if(!vis[root->val]) q.push(root);
                }
                
            }
            if(d==k) break;
            d++;
        }
        return ans;
        
    }
};