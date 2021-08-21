class Solution {
public:
    
    vector<int> dx={0,1,0,-1}, dy={1,0,-1,0};
    
    bool valid(int x, int y, int n, int m){
        return (x>=0 and x<n and y>=0 and y<m);
    }
    
    bool check(vector<vector<int>>& a, int day){
        queue<pair<int,int>> q;
        int n=a.size(), m=a[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;++j)
            if(a[0][j]>day)
                vis[0][j]=1, q.push({0,j});
        
        while(!q.empty()){
            int r=q.front().first, c=q.front().second;
            q.pop();
            if(r==a.size()-1)
                return 1;
            for(int k=0;k<4;++k){
                int x=r+dx[k], y=c+dy[k];
                if(valid(x,y,n,m) and vis[x][y]==0 and a[x][y]>day)
                    vis[x][y]=1, q.push({x,y});
            }
        }
        return 0;
    }
    
    int latestDayToCross(int n, int m, vector<vector<int>>& cells) {
        vector<vector<int>> a(n,vector<int>(m,0));
        for(int i=0;i<cells.size();++i){
            a[cells[i][0]-1][cells[i][1]-1]=i+1;
        }
        int l=0, h=cells.size(), mid, ans=0;
        while(l<=h){
            mid=(l+h)/2;
            if(check(a,mid)){
                ans=mid;
                l=mid+1;
            }
            else  
                h=mid-1;
        }
        return ans;
    }
};