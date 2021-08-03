class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(3,0);
        int mod = 1e9 + 7;
        for (int& a: nums)
            dp[a] = ((dp[a] + dp[a]) % mod + (a > 0 ? dp[a-1] : 1)) % mod;
        return dp[2];
    }
};


