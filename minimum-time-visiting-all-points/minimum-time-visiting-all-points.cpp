class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=1;i<n;i++){
            int ma = min(abs(nums[i][0]-nums[i-1][0]),abs(nums[i][1]-nums[i-1][1]));
            ans+=ma;
            if(abs(nums[i][0]-nums[i-1][0])==ma) ans+=abs(abs(nums[i][1]-nums[i-1][1])-ma);
            else{
                ans+=abs(abs(nums[i][0]-nums[i-1][0])-ma);
            }
        }
        return ans;
    }
};