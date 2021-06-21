class Solution {
public:
    int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& mat,int n,int m,int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        int ma = 0;
        for(int k=0;k<4;k++){
            int x = i+d[k][0];
            int y = j+d[k][1];
            if(x>=0 && y>=0 && x<=n-1 && y<=m-1 && mat[x][y]>mat[i][j]){
                int neigh = dfs(mat,n,m,x,y);
                ma = max(ma,neigh);
            }
        }
        return dp[i][j] = ma+1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 1;
        dp.resize(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int path = dfs(mat,n,m,i,j);
                // if(path>ans){
                //     cout << i << " " << j << " " << path << endl;
                // }
                ans = max(ans,path);
            }
        }
        return ans;
    }
};