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
    vector<TreeNode*> generateTrees(int A) {
        vector<TreeNode*> ans;
        vector<vector<vector<TreeNode*>>> dp(A+2,vector<vector<TreeNode*>>(A+2));
       
        for(int i=0;i<=A+1;i++){
            for(int j=0;j<=i-1;j++){
                dp[i][j].push_back(NULL);
            }
        }
        
        for(int len=1;len<=A;len++){
            for(int l=1;l+len-1<=A;l++){
                int r=l+len-1;
                for(int root=l; root<=r; root++){
                    for(auto a:dp[l][root-1]){
                        for(auto b:dp[root+1][r]){
                            TreeNode* cur=new TreeNode(root);
                            cur->left=a;
                            cur->right=b;
                            dp[l][r].push_back(cur);
                        }
                    }
                    
                }
                
            }
            
        }
        
        return dp[1][A];
        
    }
};