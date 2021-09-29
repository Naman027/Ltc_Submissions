class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n,0),dlis(n,0); 
        lis[0] = 1;
        vector<int> cur;
        vector<int> pref(n),suff(n);
        pref[0] = nums[0];
        cur.push_back(nums[0]);
        int len = 1;
        for(int i=1;i<n;i++){
            int ind = lower_bound(cur.begin(),cur.end(),nums[i])-cur.begin();
            if(ind!=len){
                cur[ind] = nums[i];
            }
            else{
                len++;
                cur.push_back(nums[i]);
            }
            lis[i] = len;
            pref[i] = cur.back();
        }

        vector<int> curd;
        curd.push_back(nums[n-1]);
        dlis[n-1] = 1;
        len = 1;
        suff[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            int ind = lower_bound(curd.begin(), curd.end(),nums[i])-curd.begin();
            if(ind!=len){
                curd[ind] = nums[i];
            }
            else{
                len++;
                curd.push_back(nums[i]);
            }
            dlis[i] = len;
            suff[i] = curd.back();
        }

        int ans = n;
        for(int i=1;i<n-1;i++){
            if(pref[i]>suff[i+1] && lis[i]>=2)
            ans = min(ans,n-(lis[i]+dlis[i+1]));
        }

        return ans;

    }
};