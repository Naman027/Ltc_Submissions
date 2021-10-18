class Solution {
public:
    bool static comp(const string& a, const string& b){
        return a.length()<b.length();
    }
    
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> dp;
        sort(words.begin(),words.end(),comp);
        int ans=1;
        for(string s:words){
            dp[s]=1;
            if(s.length()<=1)
                continue;
            for(int i=0;i<s.length();++i){
                string t=s;
                t.erase(t.begin()+i);
                if(dp.count(t)>0)
                    dp[s]=max(dp[s],dp[t]+1);
            }
            // cout<<s<<" "<<dp[s]<<"\n";
            ans=max(ans,dp[s]);
        }
        return ans;
    }
};