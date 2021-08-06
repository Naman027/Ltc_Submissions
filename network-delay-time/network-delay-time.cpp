typedef pair<int,int> pii;
class Solution {
public:
    const int inf = 1e9;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,inf);
        vector<pii> adj[n+1];
        for(auto v:times){
            adj[v[0]].push_back({v[1],v[2]});
        }
        
        dist[k] = 0;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            pii p = pq.top();
            pq.pop();
            
            int node = p.second;
            int dis = p.first;
            
            for(auto to:adj[node]){
                int w = to.second;
                int v = to.first;
                if(dist[v]>dis+w){
                    dist[v] = dis+w;
                    pq.push({dist[v],v});
                }
            }
        }
        
        int ans = *max_element(dist.begin()+1,dist.end());
        return (ans==inf)?-1:ans;
        
    }
};