class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n,1);
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                if(a[i]<=a[i-1]) a[i] = 1+a[i-1];
            }
        }
        
        for(int i=n-1;i>=1;i--){
            if(nums[i-1]>nums[i]){
                if(a[i-1]<=a[i]) a[i-1] = 1+a[i];
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++) ans+=a[i];
        return ans;
        
    }
};