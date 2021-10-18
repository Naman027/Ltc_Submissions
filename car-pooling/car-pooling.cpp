class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<int> a(1002,0);

        for(auto v:trips){
            a[v[1]]+=v[0];
            a[v[2]]-=v[0];
        }

        int cur = 0;
        for(int i=0;i<1002;i++){
            cur+=a[i];
            if(cur>capacity) return 0;
        }
        return 1;
    }
};