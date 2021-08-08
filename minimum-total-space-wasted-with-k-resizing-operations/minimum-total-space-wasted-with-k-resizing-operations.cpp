class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> st(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            int ma = 0,s = 0;
            for(int j=i;j<n;j++){
                ma = max(ma,nums[j]);
                s+=nums[j];
                st[i][j] = ma*(j-i+1) - s;
            }
        }
        
        vector<vector<int>> dp(n,vector<int>(k+1,INT_MAX));
        dp[0][0] = 0;
        for(int i=0;i<n;i++) dp[i][0] = st[0][i];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=k;j++) dp[i][j] = 0;
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<=k;j++){
                for(int p=0;p<i;p++){
                    dp[i][j] = min(dp[i][j],dp[p][j-1]+st[p+1][i]);
                }
            }
        }
        return dp[n-1][k];
    }
};