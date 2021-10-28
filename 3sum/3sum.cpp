class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]=i;
        
        set<vector<int>> st;
     
        for(int i=0;i<n; i++){
           if(i>0 && nums[i]==nums[i-1]) continue;
           for(int j=i+1;j<n; j++){
              
               int cur=nums[i]+nums[j];
               if(mp[-cur]>j){
                   vector<int> p;
                   p.push_back(nums[i]);
                   p.push_back(nums[j]);
                   p.push_back(-cur);            
                   st.insert(p);
               }
           }
        }
        
        for(auto i:st) ans.push_back(i);
        
        return ans;
        
    }
};