class Solution {
public:
    
    map<int,int> mp;

    int find(int n){
        if(n==1){
            return 1;
        }
        if(mp.count(n)) return mp[n];

        if(n%2==0) return mp[n] = 1+find(n/2);
        else return mp[n] = 1+find(3*n+1);    
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> ans;
        for(int i=lo;i<=hi;i++) {
            ans.push_back({find(i),i});
        }
        sort(begin(ans),end(ans));
        k--;
        return ans[k].second;
    }
};