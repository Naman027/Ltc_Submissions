class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
        for(int l = 0; l < n; l++){
            vector<int> sums(m, 0);
            for(int r = l; r < n; r++){
                for(int i = 0; i < m; i++){
                    sums[i] += matrix[i][r];
                }
                
                set<int> s;
                s.insert(0);
                int curSum = 0, curMax = INT_MIN;
                for(int sum : sums){
                    curSum += sum;
                    auto it = s.lower_bound(curSum - k);
                    if(it != s.end()){
                        curMax = max(curMax, curSum - *it);
                    }
                    s.insert(curSum);
                }
                res = max(res, curMax);
            }
        }
        return res;
    }
};