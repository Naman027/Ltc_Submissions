class NumArray {
public:
    vector<int> bit;
    vector<int> a;
    int n;
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        a = nums;
        bit = vector<int>(n+1,0);
        
        for(int i=0;i<n;i++){
            update_bit(i,a[i]);
        }
    }
    
    void update_bit(int ind,int val){
        ind++;
        while(ind<=n){
            bit[ind]+=val;
            ind+=(ind&(-ind));
        }
    }
    
    void update(int index, int val) {
        update_bit(index,val-a[index]);
        a[index] = val;
    }
    
    int query(int ind){
        ind++;
        int ans = 0;
        while(ind>0){
            ans+=bit[ind];
            ind-=(ind&(-ind));
        }
        return ans;
    }
    
    int sumRange(int left, int right) {
        return query(right)-query(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */