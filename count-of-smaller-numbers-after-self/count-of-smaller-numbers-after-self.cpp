class Solution {
public:

    class BIT{
    public:
        vector<int> bit;
        int n;

        BIT(int n){
            bit = vector<int>(n+1,0);
            this->n = n+1;
        }

        void update(int ind,int v){
            while(ind<=n){
                bit[ind]+=v;
                ind+=(ind&(-ind));
            }
        }

        int query(int ind){
            int ans = 0;
            while(ind){
                ans+=bit[ind];
                ind-=(ind&(-ind));
            }
            return ans;
        }

        int sum(int l,int r){
            return query(r)-query(l-1);
        }

    };

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        BIT bit = BIT(20010);

        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            nums[i]+=1e4+5;
            bit.update(nums[i],1);
            int q = bit.sum(1,nums[i]-1);
            ans.push_back(q);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
