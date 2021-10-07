class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        vector<int> pref(n,0),suff(n,0);
        int ans= 0;
        pref[0] = nums[0];
        for(int i=1;i<n;i++){
            if(i%2) pref[i] = pref[i-1]-nums[i];
            else pref[i]= pref[i-1]+nums[i];
        }
        
        suff[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            int len = n-i-1;
            if(len%2) suff[i] = suff[i+1]-nums[i];
            else suff[i] = suff[i+1] + nums[i];
        }
        
        for(int i=0;i<n;i++){
            if(i==0){
                if(suff[i+1]==0) ans++;
                continue;
            }
            if(i==n-1){
                if(pref[i-1]==0) ans++;
                continue;
            }
            
            int cur = pref[i-1];
            int val = pref[n-1]-pref[i];
            cur-=val;
            //cout << i << " " <<  cur << endl;
            if(cur==0) ans++;
        }
        
        return ans;
    }
};