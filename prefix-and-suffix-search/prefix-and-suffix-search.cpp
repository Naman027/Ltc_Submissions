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

class WordFilter {
public:

    class trie{
    public:
        int val;
        trie* child[27];
        trie(int v){
            val = v;
            for(int i=0;i<27;i++) child[i] = nullptr;
        }
    };

    trie* root = new trie(-1);

    void insert(string s,int index){
        int n = s.size();
        trie* temp = root;
        for(int i=0;i<n;i++){
            int ind = s[i]-'a';
            if(ind<0 || ind>25) ind = 26; 
            if(temp->child[ind]==nullptr) temp->child[ind] = new trie(-1);
            temp = temp->child[ind];
        }
        temp->val = index;
    }

    int search(string s){
        int n = s.size();
        trie* temp = root;
        for(int i=0;i<n;i++){
            int ind = s[i]-'a';
            if(ind<0 || ind>25) ind = 26; 
            if(temp->child[ind]==nullptr) return -1;
            temp = temp->child[ind];
        }
        return temp->val;
    }

    WordFilter(vector<string>& words) {
        int n = words.size();
        for(int i=0;i<n;i++){
            string s = words[i];
            int m = s.size();
            for(int l1=1;l1<=m;l1++){
                for(int l2=1;l2<=m;l2++){
                    string s1 = s.substr(0,l1);
                    s1.append("#");
                    s1.append(s.substr(m-l2,l2));
                    insert(s1,i);
                }
            }
        }        
    }
    
    int f(string prefix, string suffix) {
        string tosearch = prefix;
        tosearch.append("#");
        tosearch.append(suffix);
        return search(tosearch);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */