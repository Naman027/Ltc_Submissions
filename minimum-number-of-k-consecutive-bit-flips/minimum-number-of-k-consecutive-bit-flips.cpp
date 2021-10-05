class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        vector<int> flip(n,0);
        
        int ans = 0;
        for(int i=0;i+k-1<=n-1;i++){
            flips+=flip[i];
            int changes = flips%2;
            
            int value = ((changes>0)?1-nums[i]:nums[i]);
            if(value==1) continue;
            
            ans++;
            if(i+1<n)
                flip[i+1]+=1;
            if(i+k<n) flip[i+k]-=1;
        }
        
        for(int i=n-k+1;i<n;i++){
            flips+=flip[i];
            int changes = flips%2;
            
            int value = ((changes>0)?1-nums[i]:nums[i]);
            if(value==0) return -1;
        }
        
        return ans;
        
    }
};