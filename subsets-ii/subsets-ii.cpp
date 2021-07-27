class Solution {
public:
    map<vector<int>,int> mp;
    vector<vector<int>> ans;
    
    void per(vector<int>& nums,vector<int>& cur,int l,int r){
        vector<int> pcur = cur;
           sort(pcur.begin(),pcur.end());
        if(mp[pcur]==0){
            ans.push_back(pcur); 
            mp[pcur]++;
       }
 
        for(int i=l;i<nums.size(); i++){
            cur.push_back(nums[i]);
            per(nums,cur,i+1,r);
            cur.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        int n=nums.size();
        vector<int> cur;
        cur.clear();
        
        per(nums,cur,0,n-1);
       
        return ans;
    }
};