class Solution {
public:
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int pos[m][n];
        int ans = 0;
        memset(pos,0,sizeof(pos));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) pos[i][j] = 1;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        
        if(q.size()>=1) ans = -1;
        while(!q.empty()){
            int l = q.size();
            ans++;
            while(l--){
                pair<int,int> p = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int newx = p.first+dx[i];
                    int newy = p.second+dy[i];
                    if(newx>=0 && newy>=0 && newx<=m-1 && newy<=n-1 && pos[newx][newy]==1){
                        q.push({newx,newy});
                        pos[newx][newy] = 0;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pos[i][j]==1) return -1;
            }
        }
        return ans;
    }
};