#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long long double

class Solution {
public:

    static bool comp(vector<int>& a,vector<int>& b){
        if(a[0]<b[0]) return 1;
        else if(a[0]>b[0]) return 0;
        else return a[1]>=b[1];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),comp);

        int ans = 0;
        for(int i=0;i<n;i++){
            int j = i;
            while(j<n && intervals[j][0]>=intervals[i][0] && intervals[j][1]<=intervals[i][1]) j++;
            j--;
            i = j;
            ans++;
        }

        return ans;

    }
};
