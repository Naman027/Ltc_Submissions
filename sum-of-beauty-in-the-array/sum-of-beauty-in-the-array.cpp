class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> mi(n,1e7);
        mi[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            mi[i] = min(mi[i+1],nums[i]);
        }
        
        int ma = nums[0];
        for(int i=1;i<n-1;i++){
            if(nums[i]>ma && nums[i]<mi[i+1]) ans+=2;
            else if(nums[i+1]>nums[i] && nums[i]>nums[i-1]) ans++;
            ma = max(ma,nums[i]);
        }
        return ans;
    }
};