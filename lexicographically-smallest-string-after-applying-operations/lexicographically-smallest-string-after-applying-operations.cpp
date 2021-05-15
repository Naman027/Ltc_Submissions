class Solution {
public:
    
    string shifted(string s,int b){
        int n = s.size();
        string d = s;
        for(int i=0;i<n;i++){
            s[(i+b)%n] = d[i];
        }
        return s;
    }
    
    string oddind(string s,int a){
        int n = s.size();
        for(int i=1;i<n;i+=2){
            int ind = s[i]-'0';
            ind+=a;
            ind%=10;
            char c = char('0'+ind);
            s[i] = c;
        }
        return s;
    }
    
    string findLexSmallestString(string s, int a, int b) {
        string ans = s;
        queue<string> q;
        q.push(s);
        map<string,int> mp;
        mp[s] = 1;
        while(!q.empty()){
            string cur = q.front();
            q.pop();
            ans = min(ans,cur);
            string s1 = oddind(cur,a);
            string s2 = shifted(cur,b);
            
            if(!mp.count(s1)){
                q.push(s1);
                mp[s1] = 1;
            }
            
            if(!mp.count(s2)){
                q.push(s2);
                mp[s2] = 1;
            }
            
        }
        return ans;
    }
};