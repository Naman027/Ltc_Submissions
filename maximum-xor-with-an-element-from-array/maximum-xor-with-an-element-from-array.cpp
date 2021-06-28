class Solution {
class node{
public:
    node* child[2];
    node(){
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

    void insert(node* root,int num){
        node* tempRoot = root;
        for(int i=31;i>=0;i--){
            int bit = ((num>>i)&1);
            if(tempRoot->child[bit]==nullptr){
                tempRoot->child[bit] = new node();            
            }
            tempRoot = tempRoot->child[bit];
        }
    }

    int maxXor(node* root,int y){
        int ret = 0;
        node* tempRoot = root;
        for(int i=31;i>=0;i--){
            int bit = ((y>>i)&1);
            if(tempRoot->child[bit^1] == nullptr){
                tempRoot = tempRoot->child[bit];
            }
            else{
                ret|=(1LL<<i);
                tempRoot = tempRoot->child[bit^1];
            }
        }   
        return ret;
    }    

public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        vector<pair<pair<int,int>,int>> pq;
        for(int i=0;i<queries.size();i++){
            pq.push_back({{queries[i][0],queries[i][1]},i});
        }
        auto comp = [&](pair<pair<int,int>,int>& a,pair<pair<int,int>,int>& b){
            return (a.first.second<b.first.second);
        };
        sort(begin(pq),end(pq),comp);
        int j = 0;
        vector<int> ans(pq.size(),-1);
        node* root = new node();
        for(auto q:pq){
            int val = q.first.first;
            int num = q.first.second;
            int idx = q.second;
            while(j<n && nums[j]<=num) insert(root,nums[j]),j++;
            if(j>=1){
                int maxAns = maxXor(root,val);
                ans[idx] = maxAns;
            } 
        }
        return ans;
    }
};