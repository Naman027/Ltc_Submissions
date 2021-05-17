class Solution {
    public boolean canIWin(int n, int t) {
        if(t<=n) return true;
        if(n*(1+n)/2 < t) return false;
        
        int[] dp = new int[1+(1<<n)];
        for(int i=0;i<=(1<<n);i++) dp[i] = -1;
        return solve(n,t,dp,0,0);
    }
    
    public boolean solve(int n,int t,int[] dp,int sum,int taken){
        if(sum>=t) return false;
        if(dp[taken]!=-1) return (dp[taken]==1);
        
        for(int i=1;i<=n;i++){
            int bit = (taken&(1<<(i-1)));
            if(bit!=0) continue;
            if(solve(n,t,dp,sum+i,(taken|(1<<(i-1))))==false){
                dp[taken] = 1;
                return true;
            }
        }
        
        dp[taken] = 0;
        return false;
    }
    
}


