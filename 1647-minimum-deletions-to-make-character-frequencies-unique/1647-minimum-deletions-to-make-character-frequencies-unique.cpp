class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        int a[26];
        for(int i=0;i<26;i++) a[i]=0;
        for(int i=0;i<n;i++) a[s[i]-'a']++;
        
        vector<int> b;
        for(int i=0;i<26;i++){
            if(a[i]>=1) b.push_back(a[i]);
        }
        cout << b.size() << endl;
        map<int,int> mp;
        int ans=0;
        sort(b.begin(),b.end());
        mp[b[0]]++;
        for(int i=1;i<b.size();i++){
            if(b[i]==b[i-1]){
                mp[b[i]]++;
                for(int j=b[i]-1;j>=0;j--){
                    if(mp[j]==0){
                        ans+=(b[i]-j);
                        if(j!=0) mp[j]++;
                        break;
                    }
                }
            }
            else{
                mp[b[i]]++;
            }
            cout << ans << endl;
        }
        return ans;
    }
};