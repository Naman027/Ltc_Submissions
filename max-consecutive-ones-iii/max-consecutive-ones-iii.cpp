class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, j;
        int ans = 0;
        for (j = 0; j < A.size(); ++j) {
            if (A[j] == 0) K--;
            if (K < 0 && A[i++] == 0) K++;
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};