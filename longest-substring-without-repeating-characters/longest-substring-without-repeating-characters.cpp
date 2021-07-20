class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0,maxind=-1;
        if(n==1) return 1;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            int last=0;
            if(mp.find(s[i])!=mp.end()) last=mp[s[i]];
            else last = -1;
            maxind=max(maxind,last);
            ans=max(ans,i-maxind);
            mp[s[i]]=i;
        }
        return ans;
    }
};