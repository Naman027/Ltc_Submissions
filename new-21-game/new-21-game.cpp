class Solution {
public:
    // ans = p(n)+p(n-1)...+p(k)
    double new21Game(int n, int k, int maxPts) {
        if(k==0 || k+maxPts-1<=n) return 1.0;
        vector<double> dp(n+1);
        dp[0] = 1.0;
        double cur = dp[0];
        double ans = 0;
        for(int i=1;i<=n;i++){
            dp[i] = cur/(maxPts*1.0);
            if(i<k){
                cur+=dp[i];
            }
            else{
                ans+=dp[i];
            }
            if(i-maxPts>=0) cur-=dp[i-maxPts];
        }
        return ans;
    }
};