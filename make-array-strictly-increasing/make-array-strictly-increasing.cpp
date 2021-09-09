class Solution {
public:
    
    int fun(int ind,int prev,vector<int>& arr1,vector<int>& arr2,int n,vector<unordered_map<int,int>>& dp){
        if(ind==n) return 0;
        
        if(dp[ind].find(prev)!=dp[ind].end()) return dp[ind][prev];
        
        int ans1=INT_MAX,ans2=INT_MAX;
        if(arr1[ind]>prev){
            ans1 = fun(ind+1,arr1[ind],arr1,arr2,n,dp);
        }
        
        int index = upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        if(index!=arr2.size()) ans2 = fun(ind+1,arr2[index],arr1,arr2,n,dp);
        
        if(ans2==INT_MAX) dp[ind][prev] = ans1;
        else dp[ind][prev] = min(ans1,ans2+1);
        
        return dp[ind][prev];
        
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<unordered_map<int,int>> dp(2005);
        sort(begin(arr2),end(arr2));
        int ans = fun(0,INT_MIN,arr1,arr2,n,dp);
        if(ans==INT_MAX) ans = -1;
        return ans;
    }
};