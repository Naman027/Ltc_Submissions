class Solution {
public:

    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<long long> dp(n+1,0);
        sort(rides.begin(),rides.end());
        int m = rides.size();
        int k = 0;
        long long maxcur = 0;
        for(int i=1;i<=n;i++){
            maxcur = max(maxcur,dp[i]);
            while(k<m && rides[k][0]==i){
                dp[rides[k][1]] = max(dp[rides[k][1]],maxcur+(long long)rides[k][1]-(long long)rides[k][0]+(long long)rides[k][2]);
                k++;
            }
            maxcur = max(maxcur,dp[i]);
            dp[i] = maxcur;
            //cout << dp[i] << " ";
        }
        
        return dp[n];
    }
};