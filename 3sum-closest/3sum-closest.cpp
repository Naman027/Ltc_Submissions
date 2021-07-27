class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        int n = nums.size();
        int ans = INT_MAX, diff = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int cur = nums[i]+nums[j]+nums[k];
                if(cur==t){
                    ans = t;
                    diff = 0;
                    break;
                }
                else if(cur<t){
                    j++;
                    int diffc = abs(cur-t);
                    if(diffc<=diff){
                        diff = diffc;
                        ans = cur;
                    }
                }
                else{
                    k--;
                    int diffc = abs(cur-t);
                    if(diffc<=diff){
                        diff = diffc;
                        ans = cur;
                    }
                }
            }
        }
        return ans;
    }
};