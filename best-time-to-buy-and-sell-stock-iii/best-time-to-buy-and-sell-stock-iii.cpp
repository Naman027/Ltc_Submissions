class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        int dp[100001][2][4];
        memset(dp,0,sizeof(dp));
        
        for(int days = n-1; days>=0; days--){
            for(int trans = 0;trans<=k;trans++){
                if(days==n-1){
                    dp[days][0][trans] = 0;
                    dp[days][1][trans] = ((trans>=1)?prices[days]:0);
                }
                else{
                    dp[days][0][trans] = max(dp[days+1][0][trans],-prices[days]+dp[days+1][1][trans]);
                    dp[days][1][trans] = max(dp[days+1][1][trans], ((trans>=1)?prices[days]+dp[days+1][0][trans-1]:0));
                }
            }
        }
        return dp[0][0][k];
    }
    
    int maxProfit(vector<int>& prices) {
        return maxProfit(2,prices);   
    }
};