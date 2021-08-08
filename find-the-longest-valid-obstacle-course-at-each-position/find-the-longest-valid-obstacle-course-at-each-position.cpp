class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(lis.size()==0){
                lis.push_back(nums[i]);
                ans[i] = 1;
            }
            else{
                int ind = upper_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
                if(ind==lis.size()){
                    lis.push_back(nums[i]);
                    ans[i] = lis.size();
                }
                else{
                    lis[ind] = nums[i];
                    ans[i] = ind+1;
                }
            }
        }
        return ans;
    }
};