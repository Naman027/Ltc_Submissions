class Solution {
public:
    int dp[100000];
    int solve(vector<vector<int> > &a, int i){
        if(i>=a.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        
        // don't take current
        int ans = solve(a,i+1);
        
        // take current and search for a job which starts after current ends
        
        // find the closent job which starts after the current ends
        int s = i, e= a.size()-1;
        int idx = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(a[mid][0]<a[i][1]) s = mid+1;
            else{
                idx = mid;
                e=mid-1;
            }
        }
        
        // there is no job after the current ends
        if(idx==-1) ans = max(ans, a[i][2]);
        
        
        else ans = max(ans, a[i][2] + solve(a,idx));
        
        return dp[i]= ans;
    }
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& profit) {
        vector<vector<int> > a;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<s.size();i++){
            a.push_back({s[i],e[i],profit[i]});
        }
        sort(a.begin(),a.end());
        return solve(a,0);
    }
};
/*
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> sched;
        
        // insert all three elements (start,end,profit) into a single structure
        for(int i = 0; i < startTime.size(); ++i){
            sched.push_back({startTime[i],endTime[i],profit[i]});
        }
        
        // sort by end time 
        sort(begin(sched),end(sched),[](const vector<int> &v1, const vector<int> &v2){
           return v1[1] < v2[1]; 
        });
        
        vector<int> dp(sched.size(),0);
        dp[0] = sched[0][2];
        
        for(int i = 1; i < dp.size(); ++i){
            dp[i] = max(sched[i][2],dp[i - 1]);
            
            // perform a lower bound based on the start time of the current event
            // we want to find the first event that ends in a time <= than this start time
            auto before = lower_bound(begin(sched),begin(sched) + i,sched[i][0],
                                    [](const vector<int> &v1, const int val){
                                        return v1[1] <= val;
                                    });
            
            // lower bound can return an event that is > than what we're looking for.
            // Adjust accordingly
            while((*before)[1] > sched[i][0] && before != begin(sched)){
                before = prev(before);
            }
            
            // update the DP table
            if((*before)[1] <= sched[i][0]){
                dp[i] = max(dp[i],dp[distance(begin(sched),before)] + sched[i][2]);
            }
        }
        
        return dp[sched.size() - 1];
    }
};
*/