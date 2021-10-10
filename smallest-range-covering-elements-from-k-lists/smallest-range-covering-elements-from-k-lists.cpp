class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<pair<int,int>> a;
        for(int i=0;i<k;++i){
            for(int j:nums[i]) a.push_back({j,i});
        }
        
        sort(a.begin(),a.end());
        int count = 0;
        int mp[k];
        memset(mp,0,sizeof(mp));
        int minlen = 1e8;
        vector<int> ans;
        int j = 0;
        for(int i=0;i<a.size();i++){
            int val = a[i].first;
            int id = a[i].second;
            
            mp[id]++;
            if(mp[id]==1) count++;
            
            if(count==k){
                while(count==k){
                    if(mp[a[j].second]>1) mp[a[j].second]--,j++;
                    else break;
                }
                
                if(a[i].first-a[j].first+1<minlen){
                    minlen = a[i].first-a[j].first+1;
                    ans = {a[j].first,a[i].first};
                }
                
            }
            
        }
        
        return ans;
    }
};