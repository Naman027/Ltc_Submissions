class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        if(n==0) return ans;
        
        deque<int> dq(k);
        for(int i=0;i<n;i++){
            while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();
            
            dq.push_back(i);
           
            if(dq.front()<i-k+1) dq.pop_front();
            if(dq.back()>=k-1) ans.push_back(nums[dq.front()]); 
        }
        
        return ans;
        
    }
};