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
    bool areNumbersAscending(string s) {
        int n = s.size();
        int prev = -1;
        int cur= 0;
        for(int i=0;i<n;i++){
            if(s[i]<='9' && s[i]>='0'){
                cur = 10*cur+(s[i]-'0');
            }
            else{
                if(cur>0){
                    if(cur<=prev) return false;
                    prev = cur;
                }
                cur = 0;
            }
            //cout << cur << endl;
        }

        if(cur>0){
            if(cur<=prev) return 0;
        }
        return 1;

    }
};