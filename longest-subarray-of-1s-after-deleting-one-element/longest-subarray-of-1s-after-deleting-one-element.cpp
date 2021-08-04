class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int k = 1;
        int st = 0, end = 0;
        int ans = 0;
        for(end = 0; end<n;end++){
            if(nums[end]==0) k--;
            while(k<0){
                if(nums[st]==0) k++;
                st++;
            }
            ans = max(ans,end-st+1);
        }
        return ans-1;
    }
};