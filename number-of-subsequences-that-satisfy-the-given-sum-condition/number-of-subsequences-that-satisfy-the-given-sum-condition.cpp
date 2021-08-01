class Solution {
public:
    const int mod = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        long long ans = 0;
        for(int i=0;i<n;++i){
            if(nums[i]>target) break;
            int ind = upper_bound(begin(nums),end(nums),target-nums[i])-begin(nums);
            ind--;
            if(ind>=i){
                ans+=mpow(2LL,ind-i);
                ans%=mod;
            }
        }
        return ans;
    }
    
    long long mpow(long long base,long long exp){
        long long res = 1;
        base%=mod;
        while (exp > 0){
            if (exp & 1)
                res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
};