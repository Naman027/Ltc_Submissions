class Solution {
    public HashMap<Integer,List<Integer>> adj;
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        boolean[] vis = new boolean[n];
        for(int i=0;i>n;i++) vis[i]=false;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                ans++;
                dfs(isConnected,i,vis);
            }
        }
        return ans;
    }
    
    public void dfs(int[][] isConnected,int v,boolean[] vis){
        if(vis[v]==true) return;
        vis[v] = true;
        int n = isConnected.length;
        for(int i=0;i<n;i++){
            if(isConnected[v][i]==1 && vis[i]==false) dfs(isConnected,i,vis);
        }
    }
    
}