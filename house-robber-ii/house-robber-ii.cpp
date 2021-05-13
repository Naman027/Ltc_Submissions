class Solution {
public:
    
    int solve(vector<int> nums){
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        if(n==1) return nums[0];
        dp[1] = max(nums[0],nums[1]);
        int ans = dp[1];
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int ans1 = solve(vector<int>(nums.begin(),nums.end()-1));
        int ans2  = solve(vector<int>(nums.begin()+1,nums.end()));
        return max(ans1,ans2);
    }
};