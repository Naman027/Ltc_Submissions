class Solution {
public:
    vector<char> par;

    char find(char a){
        if(par[a-'a']==a) return a;
        return par[a-'a'] = find(par[a-'a']);
    }

    void uni(char a,char b){
        par[find(a)-'a'] = par[find(b)-'a'];
    }

    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        for(char i='a';i<='z';i++) par.push_back(i); 
        for(int i=0;i<n;i++) {
            if(equations[i][1]=='='){
                uni(equations[i][0],equations[i][3]);
            }
        }
    
        for(int i=0;i<n;i++){
            if(equations[i][1]!='=' && find(equations[i][0])==find(equations[i][3])){
                return false;
            }
        }
        return true;
    }
};