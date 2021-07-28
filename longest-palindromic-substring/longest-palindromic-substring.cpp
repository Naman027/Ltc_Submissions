class Solution {
public:
    
    int lo, maxlen;
    
    void extend(string s,int j,int k){
        while(j>=0 && k<s.size() && s[j]==s[k]){
            j--;
            k++;
        }
        
        int len = k-j-1;
        if(len>maxlen){
            maxlen = len;
            lo = j+1;
        }
        
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        lo = -1;
        maxlen = 0;
        for(int i=0;i<n;i++){
            extend(s,i,i);
            extend(s,i,i+1);
        }
        
        return s.substr(lo,maxlen);
    }
};