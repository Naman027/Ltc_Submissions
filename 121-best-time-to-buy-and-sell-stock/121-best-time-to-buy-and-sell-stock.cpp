class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mi = INT_MAX;
        int n = prices.size();
        for(int i=0;i<n;i++){
            mi = min(mi,prices[i]);
            ans = max(ans,prices[i]-mi);
        }
        return ans;
    }
};