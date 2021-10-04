class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& nums) {
        long long ans = 0;
        int n = nums.size();
        map<pair<long long,long long>,long long> mp;
        for(int i=0;i<n;i++){
            int g = __gcd(nums[i][0],nums[i][1]);
            mp[{nums[i][0]/g,nums[i][1]/g}]++;
        }
        
        for(auto i:mp){
            long long v = (long long)i.second;
            long long cur = v*(v-1)/2;
            ans+=cur;
        }
        
        return ans;
        
    }
};