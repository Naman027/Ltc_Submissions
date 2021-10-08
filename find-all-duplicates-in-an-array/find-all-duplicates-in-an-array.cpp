class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int N = nums.size();
        
        // 1 -> N
        for(int i=0;i<N;i++){
            int V = abs(nums[i]) - 1;
            if(nums[V]<0) ans.push_back(V+1);
            nums[V] = -nums[V];
        }
        return ans;
    }
};