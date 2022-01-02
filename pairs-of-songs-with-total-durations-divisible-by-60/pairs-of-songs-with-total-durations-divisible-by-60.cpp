#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long long double

#define endl '\n'
#define fo(i,m,n) for(int i=m;i<n;i++)
#define foe(i,m,n) for(int i=m;i<=n;i++)
#define mod 1000000007
#define mod2 998244353                                                                       
#define F first
#define S second
#define pb push_back
#define MP make_pair
#define vt vector
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
#define deb(x) cerr<<#x<<'='<<(x)<<endl;
#define debp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define deb2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll,vector<ll>,greater<ll>>
const ll INF=1e18L;
const double PI=4*atan(1);
const double eps=1e-8; 
int dx[]={-1,0,1,0,-1,1,1,-1};
int dy[]={0,1,0,-1,1,1,-1,-1};

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        map<int,int> mp;
        int ans =0;
        for(int i=0;i<n;i++){
            ans+=mp[(60-time[i]%60)%60];
            mp[time[i]%60]++;
        }
        return ans;
    }
};
