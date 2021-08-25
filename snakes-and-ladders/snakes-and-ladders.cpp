class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> arr(n*n,0);
        int i = n - 1, j = 0, index = 0, inc = 1;
        while (index < n * n) {
            arr[index++] = board[i][j];
            if (inc == 1 && j == n - 1) {
                inc = -1;
                i--;
            } else if (inc == -1 && j == 0) {
                inc = 1;
                i--;
            } else {
                j += inc;
            }
        }
        vector<bool> visited(n*n,0);
        queue<int> q;
        int start = arr[0] > -1 ? arr[0] - 1 : 0;
        q.push(start);
        visited[start] = true;
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                int cur = q.front();
                q.pop();
                if (cur == n * n - 1) {
                    return step;
                }
                for (int next = cur + 1; next <= min(cur + 6, n * n - 1); next++) {
                    int dest = arr[next] > -1 ? arr[next] - 1 : next;
                    if (!visited[dest]) {
                        visited[dest] = true;
                        q.push(dest);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};