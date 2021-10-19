class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int l=1;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j = i+l-1;
                for(int k=i;k<=j;k++){
                    int val = nums[k];
                    if(i>=1) val*=nums[i-1];
                    if(j+1<n) val*=nums[j+1];
                    int cur = 0;
                    if(i<=k-1) cur+=dp[i][k-1];
                    if(k+1<=j) cur+=dp[k+1][j];
                    dp[i][j] = max(dp[i][j],cur+val);
                }
            }
        }
        return dp[0][n-1];
    }
};