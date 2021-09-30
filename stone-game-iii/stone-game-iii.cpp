class Solution {
public:

    int help(vector<int>& stoneValue,int ind,int n,vector<int>& dp){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int ans = INT_MIN;
        ans = max(ans,stoneValue[ind]-help(stoneValue,ind+1,n,dp));
        if(ind+1<n) ans = max(ans,stoneValue[ind]+stoneValue[ind+1]-help(stoneValue,ind+2,n,dp));
        if(ind+2<n) ans = max(ans,stoneValue[ind]+stoneValue[ind+1]+stoneValue[ind+2]-help(stoneValue,ind+3,n,dp));
        return dp[ind] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n,-1);
        int alice = help(stoneValue,0,n,dp);    
        if(alice>0) return "Alice";
        else if(alice==0) return "Tie";
        return "Bob";
    }
};