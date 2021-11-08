class Solution {
public:

    bool check(vector<int>& quantities,int mid,int n){
        int m = quantities.size();
        int c = 0;
        // long long sum =0;
        for(int i=0;i<m;i++){
            c+=quantities[i]/mid;
            if(quantities[i]%mid) c++;
            // sum+=(long long)quantities[i];
        }
        
        // if(sum<n) return 0;
        if(c<=n) return 1;
        return 0;

    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();

        int lo = 1;
        int hi = *max_element(quantities.begin(),quantities.end());

        while(hi-lo>1){
            int mid = (hi+lo)/2;
            if(check(quantities,mid,n)){
                hi = mid;
            }
            else lo = mid+1;
        }

        if(check(quantities,lo,n)) return lo;
        return hi;

    }
};