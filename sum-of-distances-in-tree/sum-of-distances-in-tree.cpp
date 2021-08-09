class Solution {
public:
    int N;
    const static int M = 1e5;
    vector<int> adj[M];
    vector<int> count,ans;
    
    void dfs(int root,int par){
        for(int ch:adj[root]){
            if(ch==par) continue;
            dfs(ch,root);
            count[root]+=count[ch];
            ans[root]+=ans[ch]+count[ch];
        }
    }
    
    void dfs2(int root,int par){
        for(int ch:adj[root]){
            if(ch==par) continue;
            ans[ch] = ans[root]-count[ch]+N-count[ch];
            dfs2(ch,root);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        count.assign(N,1);
        ans.assign(N,0);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        dfs(0,-1);
        dfs2(0,-1);
        return ans;
    }
};