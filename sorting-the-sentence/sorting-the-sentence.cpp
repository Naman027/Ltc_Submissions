class Solution {
public:
    string sortSentence(string s) {
        int n = s.size();
        string ans[10],cur;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                continue;
            }
            else if(s[i]>=48 && s[i]<=57){
                int v = s[i]-'0';
                ans[v] = cur;
                cur = "";
            }
            else cur+=s[i];
        }
        
        string res;
        for(int i=0;i<=9;i++){
            if(ans[i].size()>0){
                res+=ans[i];
                res+=" ";
            }
        }
        string res1;
        for(int i=0;i<res.size()-1;i++) res1+=res[i];
        return res1;
    }
};