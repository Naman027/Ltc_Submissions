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
    unordered_map<int,int> mp;
    
    TreeNode* construct(int inl,int inr,vector<int> &in,int postl,int postr,vector<int> &post){
        if(postl>postr || inl>inr) return nullptr;
        
        int root=post[postr];
        TreeNode* newnode=new TreeNode(root);
        int ind=mp[root];
        int postrightright=postr-1;
        int postleftleft=postl;
        
        int inleftleft=inl;
        int inleftright=ind-1;
        int inrightleft=ind+1;
        int inrightright=inr;
        int rightlen=inrightright-inrightleft+1;
        int postleftright=postr-rightlen-1;
        int postrightleft=postleftright+1;
        
        newnode->left=construct(inleftleft,inleftright,in,postleftleft,postleftright,post);
        newnode->right=construct(inrightleft,inrightright,in,postrightleft,postrightright,post);
        return newnode;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n =inorder.size();
        if(n==0) return nullptr;
        
        for(int i=0;i<n;i++) mp[inorder[i]]=i;
        TreeNode* ans=construct(0,n-1,inorder,0,n-1,postorder);
        return ans;
        
    }
};