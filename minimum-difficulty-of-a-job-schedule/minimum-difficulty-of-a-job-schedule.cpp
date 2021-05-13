class Solution {
public:
    int minDifficulty(vector<int>& nums, int d) {
        int n = nums.size();
        if(n<d) return -1;
        vector<vector<int>> dp(d+1,vector<int>(n+1,INT_MAX));
        for(int i=1;i<=n;i++){
            dp[0][i] = 0;
        }
        dp[0][0] = 1;
        dp[1][1] = nums[0];
        int ma = nums[0];
        for(int i=2;i<=n;i++){
            ma = max(ma,nums[i-1]);
            dp[1][i] = ma;
        }
        for(int i=2;i<=d;i++){
            for(int j=i;j<=n;j++){
                 ma = 0;
                for(int k=j;k<=n;k++){
                    ma = max(ma,nums[k-1]);
                    dp[i][k] = min(dp[i][k],dp[i-1][j-1]+ma);
                }
            }
        }
        return dp[d][n];
    }
};