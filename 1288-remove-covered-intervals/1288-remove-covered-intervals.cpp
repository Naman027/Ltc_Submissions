#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long long double

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> indeg(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i) continue;
                if(intervals[i][0]<=intervals[j][0] && intervals[i][1]>=intervals[j][1]) indeg[j]++;
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) ans++;
        }
        return ans;
    }
};
