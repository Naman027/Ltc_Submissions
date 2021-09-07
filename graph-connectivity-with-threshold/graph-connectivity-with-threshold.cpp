class Solution {
public:
    
    int par(int a,vector<int>& parent){
        if(a==parent[a]) return a;
        return parent[a] = par(parent[a],parent);
    }
    
    void uni(int a,int b,vector<int>& parent,vector<int>& rank){
        int p1 = par(a,parent);
        int p2 = par(b,parent);
        if(p1==p2) return;
        if(rank[p1]<rank[p2]){
            parent[p1] = p2;
            rank[p2]+=rank[p1];
        }
        else{
            parent[p2] = p1;
            rank[p1]+=rank[p2];
        }
        //parent[p1] = p2;
    }
    
    vector<bool> areConnected(int n, int thresh, vector<vector<int>>& qr) {
        int q = qr.size();
        
        vector<int> parent(n+1);
        vector<int> rank(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
        
        for(int i=thresh+1;i<=n;i++){
            int p1 = par(i,parent);
            for(int j=2*i;j<=n;j+=i){
                int p2 = par(j,parent);
                if(p1!=p2)
                    uni(i,j,parent,rank);
            }
        }
        
        vector<bool> ans;
        for(int i=0;i<q;i++){
            int p1 = par(qr[i][0],parent);
            int p2 = par(qr[i][1],parent);
            //cout << p1 << " " << p2 << endl;
            if(p1==p2) ans.push_back(true);
            else ans.push_back(false);
        }        
        
        return ans;
    }
};