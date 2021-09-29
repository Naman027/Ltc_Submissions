class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.size();
        if(k>=2){
            sort(s.begin(),s.end());
            return s;
        }
        string ans=s;
        for(int i=0;i<n;i++){
            ans = min(ans,s.substr(i)+s.substr(0,i));
            //cout << ans << endl;
        }
        return ans;
        
    }
};