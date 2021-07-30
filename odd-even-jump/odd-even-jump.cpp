class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int res = 1;
        vector<pair<bool, bool>> dp(A.size());
        map<int, int> m;
        dp[A.size() - 1] = { true, true };
        m[A[A.size()-1]] = A.size()-1;
          for (int i = A.size() - 2; i >= 0; --i) {
            auto it = m.lower_bound(A[i]);
            if (it != end(m)) {
                res += dp[i].first = dp[it->second].second;
                if (it->first == A[i]) ++it;
            }
            if (it != begin(m)) dp[i].second = dp[prev(it)->second].first;
            m[A[i]] = i;
          }
          return res;
        }
};

