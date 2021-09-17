const int m = 1e9 + 7;
class Solution{
    int dp[1005][1005];
public:
    int helper(int n, int k){
        if(k>=n)
            return 0;
        
        if(k<=0)
            return 1; 
        
        if(dp[n][k]!=-1)
            return dp[n][k]; 
        
        dp[n][k] = helper(n-1, k);
        
        for(int len=1;len<n;len++)
            dp[n][k] = (dp[n][k] + helper(n-len, k-1))%m; 
        
        return dp[n][k];
    }
    
    int numberOfSets(int n, int k){
        memset(dp, -1, sizeof(dp));
        for(int i=2;i<n;i++)
            dp[i][i-1] = 1;    
        return helper(n, k);
    }
};