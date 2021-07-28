class Solution {
public:
    
    vector<int> prefix_fun(string s){
        int n = s.size();
        vector<int> pi(n,0);
        for(int i=1; i < n; i++){
            int j = pi[i-1];
            while(j>0 && s[i]!=s[j]) j = pi[j-1];
            if(s[i]==s[j]) j++;
            pi[i] = j;
        }
        return pi;
    }
    
    string shortestPalindrome(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        t = s+"#"+t;
        vector<int> pre = prefix_fun(t);
        int l = pre[t.size()-1];
        int i = n-1;
        string cur;
        while(i>=l){
            cur+=s[i];
            i--;
        }
        return cur+s;
        
    }
};