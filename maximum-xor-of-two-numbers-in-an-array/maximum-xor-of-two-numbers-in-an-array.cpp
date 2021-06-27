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
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        node* root = new node();
        for(int i=0;i<n;i++){
            insert(root,nums[i]);
            int temp = maxXor(root,nums[i]);
            ans= max(ans,temp);
        }
        return ans;
    }
};