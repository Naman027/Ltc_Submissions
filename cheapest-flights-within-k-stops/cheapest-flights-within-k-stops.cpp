class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& fl, int src, int dst, int k) {
        int m = fl.size();
        vector<vector<pair<int,int>>> g(n);
        for(auto v:fl){
            g[v[0]].push_back({v[1],v[2]});
        }
        
        int ans = INT_MAX;
        queue<vector<int>> q;
        vector<int> D(n,INT_MAX);
        q.push({0,src,k});
        D[src] = 0;
        while(!q.empty()){
            vector<int> top = q.front();
            q.pop();
            
            int dist = top[0];
            int node = top[1];
            int maxstops = top[2];
            if(node==dst) ans = min(ans,dist);
            //if(D[node]<dist) continue;
            for(auto ch:g[node]){
                int nodech = ch.first;
                int w = ch.second;
                if(D[nodech]>dist+w && maxstops>=0){
                    D[nodech] = dist+w;
                    q.push({D[nodech],nodech,maxstops-1});
                }
            }
        }
        
        ans = min(ans,D[dst]);
        if(ans==INT_MAX) ans = -1;
        return ans;
        
    }
};