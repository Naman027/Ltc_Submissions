class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n=nums.size();
        if(n==0) return 0;
        S = abs(S);
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum<S || (S+sum)%2!=0) return 0;
        sum=(S+sum)/2;
        
        int dp[n+1][sum+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(j>=nums[i-1]){
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};