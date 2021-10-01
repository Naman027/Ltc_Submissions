class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size();
        vector<int> pref(n,0);
        pref[0]=A[0];
        for(int i=1;i<n;i++) pref[i]=pref[i-1]+A[i];
        int ans=0;
        for(int i=0;i+L-1<n;i++){
            // i-> i+L-1
            int suml = pref[i+L-1];
            if(i!=0) suml-=pref[i-1];
            for(int j=i+L;j+M-1<n;j++){
                int sumr = pref[j+M-1];
                if(j!=0) sumr-=pref[j-1];
                ans=max(ans,suml+sumr);
            }
        }
        
        for(int i=0;i+M-1<n;i++){
            // i-> i+L-1
            int suml = pref[i+M-1];
            if(i!=0) suml-=pref[i-1];
            for(int j=i+M;j+L-1<n;j++){
                int sumr = pref[j+L-1];
                if(j!=0) sumr-=pref[j-1];
                ans=max(ans,suml+sumr);
            }
        }
        
        return ans;
        
    }
};