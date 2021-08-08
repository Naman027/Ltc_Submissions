class Solution {
public:
    int minSwaps(string s) {
        int ans = 0;
        int n = s.size();
        int i = 0, j = n-1;
        while(j>=0 && s[j]==']') j--;
        int op = 0, cl = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='[') op++;
            else cl++;
            if(cl>op){
                swap(s[i],s[j]);
                ans++;
                cl--;
                op++;
                while(j>=i+1 && s[j]==']') j--;
            }
        }
        return ans;
    }
};