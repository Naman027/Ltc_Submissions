class Solution {
public:
    long long numberOfWeeks(vector<int>& mile) {
        long long ans = 0;
        long long int ma = 0,sum = 0;
        int n = mile.size();
        for(int i=0;i<n;i++){
            sum+=mile[i];
            ma = max(ma,(long long)mile[i]);
        }
        
        if(ma>sum-ma+1) return 2LL*(sum-ma)+1LL;
        return sum;
        
    }
};