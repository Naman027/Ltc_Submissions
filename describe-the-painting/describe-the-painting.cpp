class Solution {
public:
vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
    long long mix[100002] = {}, sum = 0, last_i = 0;
    bool ends[100002] = {};
    vector<vector<long long>> res;
    for (auto &s : segments) {
        mix[s[0]] += s[2];
        mix[s[1]] -= s[2];
        ends[s[0]] = ends[s[1]] = true;
    }
    for (int i = 1; i < 100002; ++i) {
        if (ends[i] && sum)
            res.push_back({last_i, i, sum});
        last_i = ends[i] ? i : last_i;
        sum += mix[i];
    }
    return res;
}
};