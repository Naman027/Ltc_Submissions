class Solution {
public:
    
    int dfs(int node,vector<int>& vis,vector<int>& nums){
        vis[node] = 1;
        int ans = 0;
        if(!vis[nums[node]]) ans+=dfs(nums[node],vis,nums);
        return 1+ans;
    }
    
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n,0);
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int cur = dfs(i,vis,nums);
                ans = max(ans,cur);
            }
        }
        
        return ans;
        
    }
};