class Solution {
public:    
    int dp[50001][2][2];
    int solve(vector<int>& prices,int ind,int isOwn,int canBuy){
        if(ind>=prices.size()) return 0;
        if(dp[ind][isOwn][canBuy]!=-1) return dp[ind][isOwn][canBuy];
        
        if(isOwn){
            // I have a stock starting of day
            int op1 = prices[ind]+solve(prices,ind+1,0,0);
            int op2 = solve(prices,ind+1,1,0);
            return dp[ind][isOwn][canBuy] = max(op1,op2);
        }
        
        if(canBuy){
            // I don't have stock at starting of day
            int op1 = -prices[ind]+solve(prices,ind+1,1,0);
            int op2 = solve(prices,ind+1,0,1);
            return dp[ind][isOwn][canBuy] = max(op1,op2);
        }
        
        int op = solve(prices,ind+1,0,1);
        return dp[ind][isOwn][canBuy] = op;
        
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,0,1);
    }
};