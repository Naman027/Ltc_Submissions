class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;
        
        int ans = 0;
        int mi = INT_MAX;
        int ma = INT_MIN;
        
        for(int i=0;i<n;i++){
            mi = min(mi,nums[i]);
            ma = max(ma,nums[i]);
        }
        
        vector<int> minBuck(n-1,INT_MAX);
        vector<int> maxBuck(n-1,-1);
        int diff = ma-mi;
        int size = diff/(n-1);
        if(diff%(n-1)!=0) size++;
        for(int i=0;i<n;i++){
            if(nums[i]==mi || nums[i]==ma) continue;
            int ind = (nums[i]-mi)/size;
            
            minBuck[ind] = min(minBuck[ind],nums[i]);
            maxBuck[ind] = max(maxBuck[ind],nums[i]);
            
        }
        
        for(int i=0;i<n-1;i++){
            if(maxBuck[i]==-1) continue;
            ans = max(ans,minBuck[i]-mi);
            mi = maxBuck[i];
        }
        ans = max(ans,ma-mi);
        return ans;
    }
};