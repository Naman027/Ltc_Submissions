class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        set<int> st;
        for(int i=1;i<=n;i++) st.insert(i);

        map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        map<int,int> mm;
        for(auto i:mp){
            if(st.count(i.second)) st.erase(i.second),mm[i.first-'a'] = 1;
            else mm[i.first-'a'] = 0;
        }

        int ans = 0;
        for(auto i:mm){
            if(i.second==0){
                int c = mp[i.first+'a'];
                auto it = st.lower_bound(c);
                if(it==st.begin()){
                    ans+=c;
                }
                else{
                    it--;
                    ans+=(c- *it);
                    st.erase(*it);
                }
            }
        }

        return ans;

    }
};