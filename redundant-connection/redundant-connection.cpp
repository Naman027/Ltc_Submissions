class Solution {
public:
    int findPar(int node,vector<int>& rank,vector<int>& par){
       if(node==par[node]) return node;
        return par[node] = findPar(par[node],rank,par);
    }
    
    void uni(int a,int b,vector<int>& par,vector<int>& rank){
        a = findPar(a,rank,par);
        b = findPar(b,rank,par);
        if(rank[a]>rank[b]){
            par[b] = a;
        }
        else if(rank[b]>rank[a]){
            par[a] = b;
        }
        else{
            par[b] = a;
            rank[a]++;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n,-1);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++) par[i] = i, rank[i] = 0;
        int a = -1,b = -1;
        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            u--;
            v--;
            if(findPar(u,rank,par)!=findPar(v,rank,par)){
                uni(u,v,par,rank);
            }
            else{
                a = u;
                b = v;
            }
        }
        vector<int> ans;
        ans.push_back(a+1);
        ans.push_back(b+1);
        return ans;
        
    }
};