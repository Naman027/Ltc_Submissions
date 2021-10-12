class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size() ;
        vector<int> dp(n);
        dp[n-1] = arr[n-1];

        for(int i=n-2;i>=0;i--){
            dp[i] = min(dp[i+1],arr[i]);
        }

        int ans = 1,mx = 0;
        for(int i=0;i<n-1;i++){
            mx = max(mx,arr[i]);
            if(dp[i+1]>=mx){
                ans++;
            }
        }
        return ans;
    }
};
 