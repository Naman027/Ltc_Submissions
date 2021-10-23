class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l = 0, r= n-1;
        while(r-l>1){
            int mid = l+(r-l)/2;
            if(nums[mid]>nums[r]){
                l = mid+1;
            }
            else if(nums[mid]<nums[r]){
                r = mid;
            }
            else{
                r--;
            }
        }
        
        if(nums[r]<nums[l]) return nums[r];
        return nums[l];
        
    }
};