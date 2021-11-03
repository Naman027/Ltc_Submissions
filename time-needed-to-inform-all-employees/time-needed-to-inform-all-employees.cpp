class Solution {
public:

    int dfs(int node,int par,vector<vector<int>>& g,vector<int>& informTime){
        int v = informTime[node];
        int ans = 0;
        for(int ch:g[node]){
            if(ch!=par){
                ans = max(ans,v+dfs(ch,node,g,informTime));
            }
        }
        return ans;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> g(n+1);
        for(int i=0;i<n;i++){
            int par = manager[i];
            if(par==-1) continue;
            g[i].push_back(par);
            g[par].push_back(i);
        }

        return dfs(headID,-1,g,informTime);

    }
};