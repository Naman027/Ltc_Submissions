#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& a, int m, int n) {
        vector<vector<int>> ans;
        if(a.size() != m*n) return ans;
        ans = vector<vector<int>>(m,vector<int>(n,0));
        int r = 0, c = 0;
        for(int i=0;i<a.size();i++) {
            ans[r][c]=a[i];
            c++;
            if(c==n){
                r++;
                c = 0;
            }
        }

        return ans;

    }
};








