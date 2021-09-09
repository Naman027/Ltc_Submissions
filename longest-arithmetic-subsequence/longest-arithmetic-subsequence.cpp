class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n=A.size();
        if(n<=2) return n;
//         vector<vector<int>> dp(n);
//         vector<int> ind(20000);
//         for(int i=0;i<20000;i++) ind[i]=-1;
//         unordered_map<int,int> mp;
//         for(int i=0;i<n;i++){
//             vector<int> p(n);
//             for(int i=0;i<n;i++) p[i]=0;
//             dp[i]=p;
//         }
        
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++) dp[i][j]=2;
//         }        int ans=2;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 int cur=2*A[i]-A[j];
//                 if(cur<0 || mp.find(cur)==mp.end()) continue;
                
//                 dp[i][j]=dp[mp[cur]][i]+1;
//                 ans=max(ans,dp[i][j]);
                
//             }
//             mp[A[i]]=i;
//         }
//         return ans;
        
        vector<unordered_map<int,int>> dp(1005);
        int ans = 2;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff = A[j]-A[i];
                if(dp[i].count(diff)>0){
                    dp[j][diff] = dp[i][diff]+1;
                }
                else dp[j][diff] = 2;
            ans = max(ans,dp[j][diff]);
            }
        }
        return ans;
        
//         int result = 0;
//         vector<unordered_map<int, int>> dp(n);
        
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 int diff = A[i]-A[j];
//                 dp[i][diff] = dp[j].count(diff) > 0 ? dp[j][diff] + 1 : 2;
//                 result = max(result, dp[i][diff]);
//             }
//         }
//         return result;
        
    }
};