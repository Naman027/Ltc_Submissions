class Solution {
public:
    int arrangeCoins(int n) {
        long long int ans=0;
        long long int p=n;
        ans=(sqrt(1+8*p)-1)/2;
        return ans;
        
    }
};