class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<map<long long,bool>> dp(n);
        dp[0][0] = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i-1;j++){
                long long diff = stones[i]-stones[j];
                if(dp[j].count(diff)>0 || dp[j].count(diff-1)>0 || dp[j].count(diff+1)>0){
                    dp[i][stones[i]-stones[j]] = 1;
                }
            }
        }
        
        for(auto it:dp[n-1]){
            if(it.second==1) return 1;
        }
        return 0;
    }
};


