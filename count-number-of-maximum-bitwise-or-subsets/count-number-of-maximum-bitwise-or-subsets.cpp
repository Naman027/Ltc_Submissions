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
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int ma = 0;
        for(int mask = 0; mask<(1<<n);mask++){
            int cur = 0;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)) cur|=nums[i];
            }
            if(cur==ma){
                ans++;
            }
            else if(cur>ma){
                ma = cur;
                ans = 1;
            }
        }        

        return ans;
    }
};