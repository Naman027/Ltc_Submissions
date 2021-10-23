class Solution {
public:
    unordered_map<int,int>dp;
    unordered_map<int,vector<pair<int,int>>>m;
    int func(int c,int k,int n,vector<int>&nums){
        if(c>n)return 0;
        if(dp[k])return dp[k];
        int temp = 0;
        for(int i=0;i<2*n;i++){
            for(int j=0;j<2*n;j++){
                if(i==j)continue;
                int new_mask = (1<<i)+(1<<j);
                if((k&new_mask) == 0){
                    k|=(1<<i);
                    k|=(1<<j);
                    temp=max(temp,(c*(__gcd(nums[i],nums[j])))+func(c+1,k,n,nums));
                    k&=~(1<<i);
                    k&=~(1<<j);
                }
            }
        }
        return dp[k] = temp;
    }
    int maxScore(vector<int>& nums) {
        m.clear();
        dp.clear();
        int n = nums.size()/2;
        int k = 0;
        return func(1,k,n,nums);        
    }
};