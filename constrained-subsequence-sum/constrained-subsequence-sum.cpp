class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> dp(n,-1e9-50);
        int ans = nums[0];
        dq.push_back(0);
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            while(!dq.empty() && dq.back()<i-k) dq.pop_back();
            dp[i] = nums[i];
            if(!dq.empty()) dp[i]+=dp[dq.back()];
            dp[i] = max(dp[i],nums[i]);
            while(!dq.empty() && dp[dq.front()]<=dp[i]){
                dq.pop_front();
            }
            dq.push_front(i);
            ans = max(ans,dp[i]);
            //cout << ans << endl;
        }
        return ans;
    }
};