class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        int[] par = new int[n+1];
        for(int i=0;i<=n;i++) par[i] = -1;
        int[] ans = new int[2];
        for(int i=0;i<n;i++){
            int x = edges[i][0];
            int y = edges[i][1];
            if(uni(x,y,par)){
                ans[0] = x;
                ans[1] = y;
            }
        }
        return ans;
    }
    
    
    public boolean uni(int x,int y,int[] parent){
        int px = findPar(x,parent);
        int py = findPar(y,parent);
        
        if(px==py){
            return true;
        }
        parent[py] = px;
        return false;
        
    }
    
    public int findPar(int x,int[] parent){
        if(parent[x]==-1) return x;
        return findPar(parent[x],parent);
    }
    
}