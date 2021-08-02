class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<int> ans;
        if(n==1) return {0};
        vector<int> indeg(n,0);
        vector<int> adj[n];
        for(int i=0;i<m;i++){
            indeg[edges[i][0]]++;
            indeg[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==1) q.push(i);
        }
        
        while(n>2){
            int sz = q.size();
            n-=sz;
            //cout << n << endl;
            while(sz--){
                int fr = q.front();
                q.pop();
                //cout << fr << endl;
                for(int j:adj[fr]){
                    indeg[j]--;
                    if(indeg[j]==1) q.push(j);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};