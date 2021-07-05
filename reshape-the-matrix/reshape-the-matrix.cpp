class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        if(n*m!=r*c) return mat;
        int x = 0, y =0;
        vector<vector<int>> ans(r,vector<int>(c,-1));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans[i][j] = mat[x][y];
                y++;
                if(y==m){
                    x++;
                    y= 0;
                }
            }
        }
        return ans;
    }
};