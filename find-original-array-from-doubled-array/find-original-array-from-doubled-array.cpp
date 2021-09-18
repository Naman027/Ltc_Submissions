class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        int n = nums.size();
        if(n%2) return {};
        sort(nums.begin(),nums.end());
        vector<int> vis(n,0);
        int i = 0, j =1;
        vector<int> ans;
        while(j<n){
            if(i==n) break;
            if(vis[i]==1){
                i++;
                continue;
            }
            int cur = nums[i];
            j = max(j,i+1);
            while((j<n && nums[j]!=2*nums[i])|| (j<n && vis[j]==1)) j++;
            if(j==n) break;
            ans.push_back(nums[i]);
            vis[i] = 1;
            vis[j] = 1;
            i++;
        }
        //cout << ans.size() << endl;
        vector<int> an1;
        return ((ans.size()<n/2)?an1:ans);
        
    }
};