class Solution {
    vector<string> grid;
    vector<vector<vector<bool>>> visited;
    int height,width;
    
    bool inside(int row,int col){
        return row>=0 && row<height && col>=0 && col<width;
    }
    
    void dfs(int row,int col,int type){
        if(!inside(row,col) || visited[row][col][type]){
            return;
        }
        visited[row][col][type] = 1;
        if(type==0){
            dfs(row-1,col,2);
        }
        else if(type==1){
            dfs(row,col+1,3);
        }
        else if(type==2){
            dfs(row+1,col,0);
        }
        else{
            dfs(row,col-1,1);
        }
        
        if(grid[row][col]!='/'){
            dfs(row,col,type^1);
        }
        
        if(grid[row][col]!='\\'){
            dfs(row,col,type^3);
        }
        
    }
    
public:
    int regionsBySlashes(vector<string>& _grid) {
        grid = _grid;
        height = grid.size();
        width = grid[0].size();
        visited.clear();
        visited.resize(height,vector<vector<bool>>(width,vector<bool>(4,0)));
        int regions = 0;
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                for(int type=0;type<=3;type++){
                    if(visited[i][j][type]==1) continue;
                    dfs(i,j,type);
                    regions++;
                }
            }
        }
        return regions;
    }
};