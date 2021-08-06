class TreeAncestor {
public:
    vector<vector<int>> v;
    TreeAncestor(int n, vector<int>& parent) {
        v = vector<vector<int>>(n, vector<int>(20));
        for (int i = 0; i < n; i++) v[i][0] = parent[i];
        for (int j = 1; j < 20; j++) {
            for (int i = 0; i < n; i++) {
                if (v[i][j - 1] == -1) v[i][j] = -1;
                else v[i][j] = v[v[i][j - 1]][j - 1];
            }
        }
    }
    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 20; i++) {
            if ((k >> i) & 1) {
                node = v[node][i];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */