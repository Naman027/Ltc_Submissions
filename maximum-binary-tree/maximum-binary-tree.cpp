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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> v;
        int n = nums.size();
        for(int i=0;i<n;i++){
            TreeNode* cur = new TreeNode(nums[i]);
            while(!v.empty() && v.back()->val<nums[i]){
                cur->left = v.back();
                v.pop_back();
            }
            if(!v.empty()){
                v.back()->right = cur;
            }
            v.push_back(cur);
        }   
        return v[0];
    }
};