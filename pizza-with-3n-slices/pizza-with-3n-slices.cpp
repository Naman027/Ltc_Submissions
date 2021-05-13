class Solution {
public:
    int solve(vector<int> nums){
        int n = nums.size();
        int m = (n+1)/3;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[1][1] = nums[0];
        for(int i=2;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = max(dp[i-1][j],dp[i-2][j-1]+nums[i-1]);
            }
        }
        return dp[n][m];
    }
    
    int maxSizeSlices(vector<int>& nums) {
        int n = nums.size();
        int m = n/3;
        int ans1 = solve(vector<int>(nums.begin(),nums.end()-1));
        int ans2 = solve(vector<int>(nums.begin()+1,nums.end()));
        return max(ans1,ans2);
        
    }
};


