class Solution {
public:

    int dp[102][102][102];

    int solve(vector<vector<int>>& grid,int r1,int c1,int c2,int n){
        int r2 = r1+c1-c2;
        if(r1>=n || r2>=n || c1>=n || c2>=n) return -1e9;
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1) return -1e9;
        if(r1==n-1 && c1==n-1) return grid[r1][c1];
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];
        int ans = -1;
        int cur = 0;
        cur+=grid[r1][c1];
        if(r1!=r2) cur+=grid[r2][c2];

        int a1 = solve(grid,r1+1,c1,c2,n);
        if(a1!=-1e9) ans = max(ans,a1);

        a1 = solve(grid,r1+1,c1,c2+1,n);
        if(a1!=-1e9) ans = max(ans,a1);

        a1 = solve(grid,r1,c1+1,c2,n);
        if(a1!=-1e9) ans = max(ans,a1);

        a1 = solve(grid,r1,c1+1,c2+1,n);
        if(a1!=-1e9) ans = max(ans,a1);
        if(ans<0) return dp[r1][c1][c2] = -1e9;
        cur+=ans;
        return dp[r1][c1][c2] = cur;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(grid,0,0,0,n);
        if(ans<0) ans = 0;
        return ans;
    }
};