class Solution {
public:
    int n,m;
    vector<vector<int>> grid;
    
    bool inside(int i,int j){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    
    int dfs(int i,int j,int gridId){
        if(!inside(i,j) || grid[i][j]!=1) return 0;
        grid[i][j] = gridId;
        return 1+ dfs(i-1,j,gridId) + dfs(i,j-1,gridId) + dfs(i+1,j,gridId) + dfs(i,j+1,gridId);
    }
    
    int largestIsland(vector<vector<int>>& _grid) {
        grid = _grid;
        n = grid.size();
        m = grid[0].size();
        map<int,int> ids;
        ids[0] = 0;
        int gridId = 2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area = dfs(i,j,gridId);
                    ids[gridId] = area;
                    gridId++;
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    set<int> st;
                    if(i>=1) st.insert(grid[i-1][j]);
                    if(i+1<n) st.insert(grid[i+1][j]);
                    if(j>=1) st.insert(grid[i][j-1]);
                    if(j+1<m) st.insert(grid[i][j+1]);
                    int cur = 1;
                    for(auto el:st) cur+=ids[el];
                    ans = max(ans,cur);
                }
                else{
                    ans = max(ans,ids[grid[i][j]]);
                }
            }
        }
        return ans;
    }
};