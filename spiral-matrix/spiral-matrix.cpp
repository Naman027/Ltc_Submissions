class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> ans;
        int l=0,r=m-1,dl=0,dr=n-1;
        
        while(l<=r && dl<=dr){
            for(int i=l;i<=r;i++) ans.push_back(mat[dl][i]);
            for(int i=dl+1;i<=dr;i++) ans.push_back(mat[i][r]);
            if(dr-dl>=1)
                for(int i=r-1;i>=l;i--) ans.push_back(mat[dr][i]);
            if(r-l>=1)
                for(int i=dr-1;i>=l+1;i--) ans.push_back(mat[i][l]);
            l++;
            r--;
            dl++;
            dr--;
        }
        
        return ans;
        
    }
};