class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        int dp[101][101];
        memset(dp,0,sizeof(dp));
        int ans = 0;        
        for(int i=0;i<N;i++){
            string cur = strs[i];
            int z = 0, o = 0;
            for(char c:cur){
                if(c=='1') o++;
                else z++;
            }

            for(int j=m;j>=z;j--){
                for(int k=n;k>=o;k--){
                    dp[j][k] = max(dp[j][k],dp[j-z][k-o]+1);
                    ans = max(ans,dp[j][k]);
                }
            }

        }   
        return ans;
    }
};