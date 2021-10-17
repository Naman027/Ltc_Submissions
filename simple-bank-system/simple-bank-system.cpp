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

class Bank {
public:
    vector<long long> balance;
    Bank(vector<long long>& balance) {
        int n = balance.size();
        //this->balance = vector<long long>(n);
        this->balance = balance;
        //cout << this->balance.size() << endl;
    }
    
    bool transfer(int account1, int account2, long long money) {
        account1--;
        account2--;
        if(account1>=balance.size()) return 0;
        if(account2>=balance.size()) return 0;
        if(balance[account1]>=money){
            balance[account1]-=money;
            balance[account2]+=money;
            return 1;
        }
        return 0;
    }
    
    bool deposit(int account, long long money) {
        account--;
        if(account>=balance.size()) return 0;
        balance[account]+=money;
        return 1;
    }
    
    bool withdraw(int account, long long money) {
        account--;
        if(account>=balance.size()) return 0;
        if(balance[account]>=money){
            balance[account]-=money;
            return 1;
        }
        return 0;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */