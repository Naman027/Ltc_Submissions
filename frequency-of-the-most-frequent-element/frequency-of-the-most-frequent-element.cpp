typedef long long int ll;
class Solution {
public:
    
    bool check(int k,int mid,vector<int> &nums,vector<ll> &pref){
        int n = nums.size();
        for(int i=0;i+mid-1<=n-1;i++){
            ll sum = (ll)((ll)nums[i+mid-1]*(ll)mid) - pref[i+mid-1];
            if(i>=1) sum+=pref[i-1];
            //cout << i << " " << sum << endl;
            if(sum<=k) return 1;
        }
        return false;
    }
    
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long sum = 0;
        int ans = 0;
        int i = 0, j=0;
        for(j=0;j<n;j++){
            sum+=(long long)nums[j];
            while(sum+k<(long long)nums[j]*(long long)(j-i+1)) sum-=nums[i], i++;
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};