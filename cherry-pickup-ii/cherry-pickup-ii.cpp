class Solution {
public:
    int dy[3] = {-1,0,1};
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n+1][m+1][m+1];
        memset(dp,-1,sizeof(dp));
        if(m!=1)
            dp[0][0][m-1] = grid[0][0]+grid[0][m-1];
        else dp[0][0][m-1] = grid[0][0];
        for(int i=1;i<n;i++){
            for(int col1=0;col1<m;col1++){
                for(int col2=0;col2<m;col2++){
                    int res = 0;
                    res+=grid[i][col1];
                    if(col1!=col2) res+=grid[i][col2];
                    int ma = -1;
                    for(int k=0;k<3;k++){
                        for(int k1=0;k1<3;k1++){
                            int newcol1 = col1+dy[k];
                            int newcol2 = col2+dy[k1];
                                
                            if(newcol1>=0 && newcol1<m && newcol2>=0 && newcol2<m){
                                ma = max(ma,dp[i-1][newcol1][newcol2]);
                            }
                        }
                    }
                    if(ma!=-1){
                        ma+=res;
                        dp[i][col1][col2] = ma;
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++) ans = max(ans,dp[n-1][i][j]);
        }
        return ans;
    }
};