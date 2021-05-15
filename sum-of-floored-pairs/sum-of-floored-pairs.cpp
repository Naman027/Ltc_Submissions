typedef long long int ll;
class Solution {
public:
    
    ll max(ll a,ll b){
        if(a>=b) return a;
        return b;
    }
    
    const int N = 2e5;
    ll mod = 1e9+7;
    ll solve(vector<int>& nums,int n){
        vector<ll> freq(N+1,0);
        vector<ll> preFreq(N+1,0);
        for (ll i = 0; i < n; i++) {
            freq[(ll)nums[i]]++;
        }
        for (ll i = 1; i <= N; i++) {
            preFreq[i] = preFreq[i - 1] + freq[i];
        }   
        ll ma = (ll)0;
        for(int i=0;i<n;i++) ma = max(ma,nums[i]);
        ll ans = 0;
        for (ll i = 1; i <= ma; i++) {
            for (ll j = i; j <= (ll)2*ma; j += i) {
                ll X = 0;
                if(j-i-1>=0)
                    X = (preFreq[j - 1] - preFreq[j - i - 1]);
                else X = preFreq[j - 1];
                X*=(j/i-1);
                ans += X *(ll)freq[i];
                ans%=mod;
            }
        }
        return ans;
    }
    
    
    int sumOfFlooredPairs(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,n)%mod;
        
    }
};