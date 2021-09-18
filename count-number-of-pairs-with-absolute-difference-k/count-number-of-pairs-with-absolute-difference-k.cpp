class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int lind = lower_bound(nums.begin(),nums.end(),nums[i]+k)-nums.begin();
            int rind = upper_bound(nums.begin(),nums.end(),nums[i]+k)-nums.begin();
            rind--;
            lind = max(lind,i+1);
            if(rind>=lind) ans+=(rind-lind+1);
        }
        return ans;
    }
};