class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        map<int,int> mp;
        int sum = 0;
        int ans = n+10;
        mp[0] = -1;
        vector<int> dp(n,INT_MAX);
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mp.find(sum-target)!=mp.end()){
                int prevind = mp[sum-target];
                int len = i-prevind;
                //cout << len << " " << prevind << endl;
                if(i>=1){
                    if(prevind>=0 && dp[prevind]!=INT_MAX){
                        ans = min(ans,dp[prevind]+len);   
                        dp[i] = min(dp[i-1],len);
                    }
                    else if(prevind==-1){
                        dp[i] = len;
                    }
                    else if(dp[prevind]==INT_MAX){
                        dp[i] = len;
                    }
                }
                else if(i==0){
                    dp[i] = 1;
                }
            }
            else{
                if(i>=1) dp[i] = dp[i-1];
            }
            mp[sum] = i;
        }
        if(ans==n+10) ans = -1;
        return ans;
        
    }
};