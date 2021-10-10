
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> cur;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                cur.push_back(grid[i][j]);
            }
        }
        
        sort(cur.begin(),cur.end());
        int ans = 0;
        int make = cur[cur.size()/2];
        for(int i=0;i<cur.size();i++){
            if(abs(cur[i]-make)%x!=0){
                return -1;
            }
            ans+=abs(cur[i]-make)/x;
        }
        return ans;
    }
};