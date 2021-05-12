class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> ispald(n+1,vector<bool>(n+1,0));
        for(int i=0;i<=n;i++) ispald[i][i] = 1;
        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j = i+l-1;
                bool ans = 0;
                if(s[i]==s[j]) ans = 1;
                if(i+1<=j-1){
                    ans*=ispald[i+1][j-1];
                }
                ispald[i][j] = ans;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(ispald[0][i] && ispald[i+1][j] && ispald[j+1][n-1]) return true;
            }
        }
        return false;
    }
};