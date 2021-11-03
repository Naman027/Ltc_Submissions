class Solution {
public:
    int numSplits(string s) {
        int ans = 0;
        int n = s.size();

        vector<int> dis(n,0),dis2(n,0);
        set<char> cs;

        for(int i=0;i<n;i++){
            cs.insert(s[i]);
            dis[i] = cs.size();
        }

        set<char> cs2;
        for(int i=n-1;i>=0;i--){
            cs2.insert(s[i]);
            dis2[i] = cs2.size();
        }

        for(int i=0;i<n-1;i++){
            //cout << dis[i] << " " << dis2[i+1] << endl;
            if(dis2[i+1]==dis[i]) ans++;
        }
        return ans;
    }
};
