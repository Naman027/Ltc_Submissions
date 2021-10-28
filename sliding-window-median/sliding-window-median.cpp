#define ll long long int
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<ll,greater<ll>> large,small;

        for(int i=0;i<k;i++){
            small.insert(nums[i]);
            large.insert(-*small.begin());
            small.erase(small.begin());
            if(small.size()<large.size()){
                small.insert(-*large.begin());
                large.erase(large.begin());
            }
        }

        vector<double> ans;
        if(small.size()>large.size()){
            ans.push_back((double)*small.begin());
        }
        else{
            double l = *small.begin();
            double r = 0.0;
            if(large.size() >=1) r = *large.begin();
            ans.push_back((l - r)/2.0);
        }

        for(int i=k;i<n;i++){
            int e = nums[i-k];
            auto it = small.find(e);
            if(it!=small.end()){
                small.erase(it);
            }
            else{
                it = large.find(-e);
                //assert(it==large.end());
                large.erase(it);
            }
            small.insert(nums[i]);
            large.insert(-*small.begin());
            small.erase(small.begin());
            if(small.size()<large.size()){
                small.insert(-*large.begin());
                large.erase(large.begin());
            }
            if(small.size()>large.size()){
                ans.push_back((double)*small.begin());
            }
            else{
                double l = *small.begin();
                double r = 0.0;
                if(large.size() >=1) r = *large.begin();
                ans.push_back((l - r)/2.0);
            }
        }
        return ans;
    }
};
