class Solution {
public:
    
    bool check(vector<int>& nums,int mid,int k){
        int cur = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%mid==0) cur+=nums[i]/mid;
            else cur+=nums[i]/mid+1;
        }
        return cur<=k;
    }
    
    int smallestDivisor(vector<int>& nums, int k) {
        int l = 1;
        int r = 1e6;
        
        while(l<r){
            int mid = (l+r)/2;
            if(check(nums,mid,k)){
                r = mid;
            }
            else l = mid+1;
        }
        return l;
    }
};