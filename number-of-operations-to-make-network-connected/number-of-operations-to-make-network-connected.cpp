class Solution {
public:
    static const int N = 10+1e5;
    vector<int> g[N];
    vector<bool> vis;
    
    void dfs(int node){
        vis[node] =1;
        for(auto child:g[node]){
            if(!vis[child]) dfs(child);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& nums) {
        int m = nums.size();
        if(m<n-1) return -1;
        vis.resize(N);
        for(int i=0;i<m;i++){
            g[nums[i][0]].push_back(nums[i][1]);
            g[nums[i][1]].push_back(nums[i][0]);
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i);
            }
        }
        
        return ans-1;
        
    }
};