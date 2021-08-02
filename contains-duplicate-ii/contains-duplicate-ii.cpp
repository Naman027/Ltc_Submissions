class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> s;
        for(int i=0;i<n;i++){
            if(i>k) s.erase(nums[i-k-1]);
            if(s.count(nums[i])) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};