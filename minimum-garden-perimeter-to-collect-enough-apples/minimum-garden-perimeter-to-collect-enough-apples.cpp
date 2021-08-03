class Solution {
public:
    long long minimumPerimeter(long long need) {
        long long lo = 1, hi = 100000;
        long long ans = 0;
        while(lo<hi){
            long long mid = (lo+hi)/2;
            long long cur = 2LL*mid*(mid+1LL)*(2LL*mid+1LL);
            if(cur>=need){
                hi = mid;
            }
            else lo = mid+1;
        }
        return 8LL*lo;
    }
};


