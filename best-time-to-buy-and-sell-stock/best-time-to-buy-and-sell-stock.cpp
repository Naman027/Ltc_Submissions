class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, cheap = nums[0];
        
        for(int i=1;i<n;i++){
            ans = max(ans,nums[i]-cheap);
            cheap = min(cheap,nums[i]);
        }
        return ans;
    }
};