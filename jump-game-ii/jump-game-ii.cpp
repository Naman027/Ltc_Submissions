class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int steps = nums[0],ans = 1;
        int ma = nums[0];
        for(int i=1;i<nums.size();i++){
            //cout << steps << endl;
            if(steps>=nums.size()-1) return ans;
            int j = i+nums[i];
            ma = max(ma,j);
            if(i==steps){
                steps = ma;
                ans++;
            }
            if(steps>=nums.size()-1) return ans;
        }
        return -1;
    }
};