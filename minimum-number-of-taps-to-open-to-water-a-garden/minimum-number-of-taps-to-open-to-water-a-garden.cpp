#include <bits/stdc++.h>
#define ll long long int
#define ld long long double
#define endl '\n'
#define loop(i,m,n) for(ll i=m;i<n;i++)
#define loope(i,m,n) for(ll i=m;i<=n;i++)
#define mod 1000000007
#define F first
#define S second
#define pb push_back
#define MP make_pair
#define vt vector
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll,vector<ll>,greater<ll>>
const ll INF=1e18L;
const double PI=4*atan(1);
const double eps=1e-8;
using namespace std;
 
int dx[]={-1,0,1,0,-1,1,1,-1};
int dy[]={0,1,0,-1,1,1,-1,-1};

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1,0);
        for(int i=0;i<sz(ranges);i++){
            int left = max(0,i-ranges[i]);
            int right = min(n,i+ranges[i]);

            dp[left] = max(dp[left],right);
        }

        int ans = 1;
        int maxstep = dp[0];
        int lastmax = -1;
        for(int i=1;i<=n;i++){
            lastmax = max(lastmax,dp[i]);
            if(i==maxstep){
                maxstep = lastmax;
                ans++;
                lastmax  = -1;
            }
            if(maxstep==n) return ans;
        }
        return -1;
    }
};


