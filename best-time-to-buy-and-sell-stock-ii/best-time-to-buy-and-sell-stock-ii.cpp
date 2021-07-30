class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n = price.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int j= i;
            while(j+1<n && price[j+1]>=price[j]) j++;
            ans+=price[j]-price[i];
            i = j;
        }
        return ans;
    }
};