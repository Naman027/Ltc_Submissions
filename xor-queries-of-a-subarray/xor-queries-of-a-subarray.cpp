class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> xo(n,0);
        xo[0] = arr[0];
        for(int i=1;i<n;i++){
            xo[i] = xo[i-1]^arr[i];
        }
        
        int q = queries.size();
        vector<int> ans;
        for(int i=0;i<q;i++){
            int x = queries[i][0];
            int y = queries[i][1];
            int cur = xo[y];
            if(x>=1) cur^=xo[x-1];
            ans.push_back(cur);
        }
        return ans;
    }
};