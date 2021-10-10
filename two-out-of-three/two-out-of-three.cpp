class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        int a[101];
        memset(a,0,sizeof(a));
        set<int> num1(nums1.begin(),nums1.end());
        set<int> num2(nums2.begin(),nums2.end());
        set<int> num3(nums3.begin(),nums3.end());
        for(int num:num1){
            a[num]++;
        }
        for(int num:num2) a[num]++;
        for(int num:num3) a[num]++;
        vector<int> ans;
        for(int i=0;i<=100;i++){
            if(a[i]>=2) ans.push_back(i);
        }
        return ans;
    }
};