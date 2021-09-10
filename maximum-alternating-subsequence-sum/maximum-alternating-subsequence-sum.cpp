typedef long long int ll;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        const ll INF = 1e14;
        vector<vector<ll>> dp(n,vector<ll>(2,-INF));
        
        dp[0][1] = (ll)nums[0];
        for(int i=1;i<=n-1;i++){
            dp[i][0] = max(dp[i-1][0],(ll)dp[i-1][1]-(ll)nums[i]);
            dp[i][1] = max(dp[i-1][1],(ll)dp[i-1][0]+(ll)nums[i]);
            dp[i][1] = max(dp[i][1],(ll)nums[i]);
        }                             
        return max(dp[n-1][0],dp[n-1][1]);
    }
};