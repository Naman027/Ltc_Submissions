class Solution {
public:
    
    int dp[50001][2];
    int fee;
    int solve(vector<int>& prices,int ind,int isOwn){
        if(ind>=prices.size()) return 0;
        if(dp[ind][isOwn]!=-1) return dp[ind][isOwn];
        
        if(isOwn){
            // I have a stock starting of day
            int op1 = prices[ind]-fee+solve(prices,ind+1,0);
            int op2 = solve(prices,ind+1,1);
            return dp[ind][isOwn] = max(op1,op2);
        }
        
        // I don't have stock at starting of day
        int op1 = -prices[ind]+solve(prices,ind+1,1);
        int op2 = solve(prices,ind+1,0);
        return dp[ind][isOwn] = max(op1,op2);
    }
    
    int maxProfit(vector<int>& prices, int _fee) {
        fee = _fee;
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,0);
    }
};