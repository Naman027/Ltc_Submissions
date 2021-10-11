class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        auto comp = [&](vector<int>& p1,vector<int>& p2) -> bool{
            return p1[1]<p2[1];
        };

        sort(points.begin(),points.end(),comp);
        int time = points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]<=time) continue;
            ans++;
            time = points[i][1];
        }

        return ans;
        
    }
};
