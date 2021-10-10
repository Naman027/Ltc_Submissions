class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        map<int,vector<int>> mp;
        
        int sum = 0;
        n/=2;
        for(int i=0;i<2*n;i++) sum+=nums[i];
        
        for(int mask = 0;mask< (1<<n);mask++){
            int set = 0;
            int cur = 0;
            for(int j=0;j<n;j++){
                if((mask&(1<<j))){
                    set++;
                    cur+=nums[j];
                }
            }
            mp[set].push_back(2*cur);
        }
        
        for(int i=0;i<=n;i++){
            sort(mp[i].begin(),mp[i].end());
        }
        
        int ans = 1e9;
        
        for(int mask=0;mask<(1<<n);mask++){
            int set = 0;
            int cur = 0;
            for(int j=0;j<n;j++){
                if(mask&(1<<j)){
                    set++;
                    cur+=nums[j+n];
                }
            }
            
            int req = n-set;
            int ind = lower_bound(mp[req].begin(),mp[req].end(),sum-2*cur)-mp[req].begin();
            if(ind<mp[req].size()){
                ans = min(ans,abs(mp[req][ind]-sum+2*cur));
            }
            ind--;
            if(ind>=0){
                ans = min(ans,abs(mp[req][ind]-sum+2*cur));                
            }
        }
        return ans;
    }
};