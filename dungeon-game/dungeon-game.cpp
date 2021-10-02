class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        dp[n-1][m-1]=min(0,dungeon[n-1][m-1]);
        for(int i=m-2;i>=0;i--){
            dp[n-1][i]=dp[n-1][i+1]+dungeon[n-1][i];
            if(dp[n-1][i]>0) dp[n-1][i]=0;
        }
        
        for(int i=n-2;i>=0;i--){
            dp[i][m-1]=dp[i+1][m-1]+dungeon[i][m-1];
            if(dp[i][m-1]>0) dp[i][m-1]=0;
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                dp[i][j]=max(dp[i+1][j],dp[i][j+1])+dungeon[i][j];
                if(dp[i][j]>0) dp[i][j]=0;
            }
        }
        
        return 1+abs(dp[0][0]);
        
    }
};