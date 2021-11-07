class Solution {
public:

    int dfs(int node,int par,vector<vector<int>>& g,vector<bool>& hasApple){
        int sum = 0;
        for(auto ch:g[node]){
            if(ch==par) continue;
            int v = dfs(ch,node,g,hasApple);
            if(v>0){
                if(v==1) sum+=2;
                else sum+=v+2;
            }
        }
        //cout << node << " " << sum << endl;
        if(sum==0) return (hasApple[node]==1);
        return sum;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<vector<int>> g(n+1);
        for(auto v:edges){
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        int ans = dfs(0,-1,g,hasApple);
        if(hasApple[0]==1 && ans==1) ans--;
        return ans;
    }
};