class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        
        int z=0,o=0,t=0;
        for(int i=0;i<n; i++){
            if(nums[i]==0) z++;
            else if(nums[i]==1) o++;
            else t++;
        }
        
        for(int i=0;i<n; i++){
            if(z>0){
               nums[i]=0;
                z--;
            }
            else if(o>0){
                nums[i]=1;
                o--;
            }
            else{
                nums[i]=2;
                t--;
            }
        }
        
    }
};