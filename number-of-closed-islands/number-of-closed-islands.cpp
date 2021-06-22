class Solution {
public:
    vector<vector<int>> grid;
    int n,m;
    vector<vector<int>> vis;
    bool f;
    void dfs(int x,int y){
        if(x<0 || y<0 || x>=n || y>=m || vis[x][y]!=0 || grid[x][y]==1) return;
        vis[x][y] = 1;
        
        if(x==0 || x==n-1) f = 0;
        if(y==0 || y==m-1) f = 0;
        dfs(x+1,y);
        dfs(x-1,y);
        dfs(x,y+1);
        dfs(x,y-1);
    }
    
    int closedIsland(vector<vector<int>>& _grid) {
        grid = _grid;
        n = grid.size();
        m = grid[0].size();
        vis.resize(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    f = 1;
                    dfs(i,j);  
                    if(f)ans++;
                }
            }
        }
        return ans;
    }
};