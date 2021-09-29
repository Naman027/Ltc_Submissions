class Solution {
public:
    
    vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0]==1 && k==0) return -1;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<vector<int>> q;
        vector<vector<int>> obst(n,vector<int>(m,0));
        q.push({0,0,grid[0][0]});
        obst[0][0] = grid[0][0];
        int lev = 0;
        vis[0][0] = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                vector<int> top = q.front();
                q.pop();
                int x0 = top[0];
                int y0 = top[1];
                int obSt = top[2];
                
                if(x0==n-1 && y0==m-1) return lev;
                
                for(auto &d:dirs){
                    int newx = x0+d[0];
                    int newy = y0+d[1];
                    if(newx>=0 && newx<=n-1 && newy<=m-1 && newy>=0){
                        int newObst = obSt+grid[newx][newy];
                        if(!vis[newx][newy] && newObst<=k){
                            q.push({newx,newy,newObst});
                            obst[newx][newy] = newObst;
                            vis[newx][newy] = 1;
                        }
                        else{
                            int oldObst = obst[newx][newy];
                            if(newObst<oldObst && newObst<=k){
                                q.push({newx,newy,newObst});
                                obst[newx][newy] = newObst;
                            }
                        }
                    }
                }
            }
                lev++;
        }
        
        return -1;
    }
};