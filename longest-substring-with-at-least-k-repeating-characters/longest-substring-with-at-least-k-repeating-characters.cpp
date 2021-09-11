class Solution {
public:
    
    int longestSubstring(string s, int K) {
        int ans = 0;
        int n = s.size();
        
        for(int i=1;i<=26;i++){
            int st = 0, end = 0;
            int u = 0, noofKmore = 0;
            vector<int> c(26,0);
            while(end<n){
                if(u<=i){
                    int idx = s[end]-'a';
                    c[idx]++;
                    if(c[idx]==1){
                        u++;
                    }
                    if(c[idx]==K) noofKmore++;
                    end++;
                }
                else{
                    int idx = s[st]-'a';
                    c[idx]--;
                    if(c[idx]==0) u--;
                    if(c[idx]==K-1) noofKmore--;
                    st++;
                }
                if(u==i && noofKmore==i) ans = max(ans,end-st);
            }
            
        }
        return ans;
    }
};