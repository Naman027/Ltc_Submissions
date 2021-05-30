class Solution {
public:
    int dp[14][16384];
    int helper(int idx,vector<int>& nums1, vector<int>& nums2,int mask)
    {
        if(idx == nums1.size())return 0;
        int ans = INT_MAX;
        if(dp[idx][mask] != -1)return dp[idx][mask];
        for(int i = 0;i<nums2.size();i++)
        {
            
            if(!(mask & (1<<i))){
                ans = min(ans,(nums1[idx]^nums2[i]) + helper(idx+1,nums1,nums2,mask|(1<<i)));
            }
        }
        return dp[idx][mask] = ans;
    }
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        
        memset(dp,-1,sizeof(dp));
        
        return helper(0,nums1,nums2,0);
    }
};