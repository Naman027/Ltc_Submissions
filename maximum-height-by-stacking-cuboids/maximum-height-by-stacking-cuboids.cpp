class Solution {
public:
    int maxHeight(vector<vector<int>>& c) {
        int n = c.size();
        for(auto &i : c)
            sort(i.begin() , i.end());
       sort(c.begin() , c.end());
        vector<int>dp(n , 0 );
        int res = -1e9;
        for(int i=0;i<n;i++){
            dp[i] = c[i][2] ;
            for(int j = 0 ; j < i ; j++){
                if(c[i][0] >= c[j][0] && c[i][1] >= c[j][1] && c[i][2] >= c[j][2]){
                    dp[i] = max(dp[i] , dp[j] + c[i][2]);
                }
            }
            res = max(res , dp[i]);
        }
       
        return res;
    }
};