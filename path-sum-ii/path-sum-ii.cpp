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

// class TreeNode{
// public:
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    
    void solve(TreeNode* root,int targetSum,vector<vector<int>>& ans,vector<int>& cur){
        if(root==nullptr) return;
        int v = root->val;
        cur.push_back(v);
        if(v==targetSum && root->left==nullptr && root->right==nullptr) ans.push_back(cur);
        solve(root->left,targetSum-v,ans,cur);
        solve(root->right,targetSum-v,ans,cur);
        cur.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> cur;
        solve(root,targetSum,ans,cur);
        return ans;    
    }
};



