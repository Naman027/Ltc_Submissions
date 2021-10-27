#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long long double

#define endl '\n'
#define fo(i,m,n) for(ll i=m;i<n;i++)
#define foe(i,m,n) for(ll i=m;i<=n;i++)
template<typename... T> void read(T&... args){ ((cin >> args),...); }
template<typename... T> void print(T... args){ ((cout << args << " "),...); }
template<typename... T> void printl(T... args){ ((cout << args << endl),...); }
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
#define SpeedForce ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0); 

const ll INF=1e18L;
const double PI=4*atan(1);
const double eps=1e-8; 
int dx[]={-1,0,1,0,-1,1,1,-1};
int dy[]={0,1,0,-1,1,1,-1,-1};

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int,vector<int>> g;

        for(int i=0;i<n;i++){
            g[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<int> vis(n,0);
        q.push(0);
        vis[0] = 1;
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int ind = q.front();
                q.pop();
                if(ind==n-1) return ans;
                vector<int> next = g[arr[ind]];
                next.push_back(ind-1);
                next.push_back(ind+1);
                for(int aage:next){
                    if(aage>=0 && aage<=n-1 && !vis[aage]){
                        vis[aage] = 1;
                        q.push(aage);
                    }
                }
                g[arr[ind]].clear();
            }
            ans++;
        }
        return -1;
    }
};


