class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c = 0, num = -1;
        for(int i=0;i<n;i++){
            if(c==0){
                num = nums[i];
            }
            if(num==nums[i]) c++;
            else c--;
        }
        return num;
    }
};