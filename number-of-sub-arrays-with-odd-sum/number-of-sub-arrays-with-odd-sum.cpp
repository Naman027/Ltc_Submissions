class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        map<int,int>  mp;
        int mod = 1e9+7;

        mp[0]++;
        int ans = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            sum%=2;
            ans+=mp[1-sum];
            mp[sum]++;
            ans%=mod;
            mp[sum]%=mod;
        }

        return ans;

    }
};
