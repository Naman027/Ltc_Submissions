class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='a'){
                if(i==n/2 && n%2!=0) continue;
                s[i] = 'a';
                return s;
            }
        }
        
        if(n==1) return "";
        s[n-1] = 'b';
        return s;
        
    }
};