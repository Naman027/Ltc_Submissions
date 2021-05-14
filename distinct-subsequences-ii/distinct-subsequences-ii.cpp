class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9+7;
        int n = s.size();
        
        vector<long long> dp(n+1,0);
        dp[0] = 1;
        vector<long long> last(26,-1);
        for(int i=1;i<=n;i++){
            dp[i] = dp[i-1]*(long long)2;
            dp[i]%=mod;
            if(last[s[i-1]-'a']!=-1){
                dp[i]-=dp[last[s[i-1]-'a']-1];
            }
            dp[i]+=mod;
            dp[i]%=mod;
            last[s[i-1]-'a'] = i;
        }
        return (dp[n]-1+mod)%mod;
    }
};