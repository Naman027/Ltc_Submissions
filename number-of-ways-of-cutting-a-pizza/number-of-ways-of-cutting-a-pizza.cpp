#define p7 1000000007
#define ll long long
ll dp[51][51][11];
class Solution {
public:

    ll num(ll r1,ll c1,ll r2,ll c2,vector<vector<ll> >& cnt){
        return cnt[r2][c2] - cnt[r1-1][c2] - cnt[r2][c1-1] + cnt[r1-1][c1-1];
    }
    
    ll solve(ll r,ll c,ll k,ll n,ll m,vector<vector<ll> >& cnt){
        if(r>n || c>m)
            return 0;
        if(k==0)
            return dp[r][c][k]=(num(r,c,n,m,cnt)!=0);
        if(num(r,c,n,m,cnt)<=k)
            return dp[r][c][k]=0;
        if(dp[r][c][k]!=-1)
            return dp[r][c][k];
        ll ans = 0;
        for(ll row=r; row<n; row++)
            if(num(r,c,row,m,cnt)!=0)
                ans=(ans+solve(row+1,c,k-1,n,m,cnt))%p7;
        for(ll col=c; col<m; col++)
            if(num(r,c,n,col,cnt)!=0)
                ans=(ans+solve(r,col+1,k-1,n,m,cnt))%p7;
        return dp[r][c][k]=(ans%p7);
    }
    
    int ways(vector<string>& a, ll k) {
        ll n = a.size();
        if(n==0)
            return 0;
        ll m = a[0].size();
        vector<vector<ll> > cnt(n+1,vector<ll>(m+1,0));
        memset(dp,-1,sizeof(dp));
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=m; j++)
                cnt[i][j] = cnt[i-1][j]+(a[i-1][j-1]=='A');
        }
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=m; j++)
                cnt[i][j] += cnt[i][j-1];
        }
        return (solve(1,1,k-1,n,m,cnt)%p7);
    }
};