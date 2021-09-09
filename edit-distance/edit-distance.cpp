class Solution {
public:
    
    int fun(int ind1,int ind2,string word1, string word2, int n,int m,vector<vector<int>>& dp){
        if(n==0) return m;
        if(m==0) return n;
        
        if(dp[n][m]!=-1) return dp[n][m];
        int ans = 0;
        if(word1[ind1]==word2[ind2]){
            ans = fun(ind1+1,ind2+1,word1,word2,n-1,m-1,dp);
        }
        else{
            int op1 = 1+fun(ind1,ind2+1,word1,word2,n,m-1,dp);
            int op2 = 1+fun(ind1+1,ind2,word1,word2,n-1,m,dp);
            int op3 = 1+fun(ind1+1,ind2+1,word1,word2,n-1,m-1,dp);
            ans = min({op1,op2,op3});
        }
        
        return dp[n][m] = ans;
        
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        return fun(0,0,word1,word2,n,m,dp);
        
    }
};