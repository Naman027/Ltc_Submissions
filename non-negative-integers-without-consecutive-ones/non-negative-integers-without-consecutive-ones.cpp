class Solution {
public:
    int findIntegers(int num) {
        int f[31];
        f[0] = 1;
        f[1] = 2;
        
        for(int i=2;i<31;i++) f[i] = f[i-1]+f[i-2];
        
        int ans = 0;
        int k = 30, pre_bit = 0;
        while(k--){
            if(num&(1<<k)){
                ans+=f[k];
                if(pre_bit) return ans;
                pre_bit = 1;
            }
            else{
                pre_bit=0;
            }
        }
        return ans+1;
    }
};