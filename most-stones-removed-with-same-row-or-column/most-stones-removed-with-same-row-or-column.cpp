class Solution {
public:
    vector<int> par;
    
    int find(int x){
        if(par[x]==x) return x;
        return par[x] = find(par[x]);
    }
    
    void uni(int x,int y){
        par[find(x)]=par[find(y)];
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n =stones.size();
        for(int i=0;i<n;i++) par.push_back(i);
        
        map<int,vector<int>> xmap;
        map<int,vector<int>> ymap;
        
        for(int i=0;i<n;i++){
            xmap[stones[i][0]].push_back(i);
            ymap[stones[i][1]].push_back(i);
        }
        
        for(int i=0;i<n;i++){
            for(int j:xmap[stones[i][0]]){
                uni(i,j);
            }
            for(int j:ymap[stones[i][1]]) uni(i,j);
        }
        
        int comp = 0;
        for(int i=0;i<n;i++){
            if(par[i]==i) comp++;
        }
        return n-comp;
    }
};