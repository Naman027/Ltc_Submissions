class Solution {
public:
    
    void merge(vector<array<int,2>>& ind,vector<int>& ans,int st,int mid,int end){
        int left = st;
        int right = mid+1;
        
        vector<array<int,2>> temp(end-st+1);
        int k = 0;
        while(left<=mid && right<=end){
            if(ind[left][0]<=ind[right][0]){
                temp[k++] = ind[right++];
            }
            else{
                ans[ind[left][1]]+=(end-right+1);
                temp[k++] = ind[left++];
            }
        }
        
        while(left<=mid){
            temp[k++] = ind[left++];
        }
        
        while(right<=end){
            temp[k++] = ind[right++];
        }
        
        for(int i=st;i<=end;i++){
            ind[i] = temp[i-st];
        }
        
    }
    
    void fun(vector<array<int,2>>& ind,vector<int>& ans,int st,int end){
        if(st<end){
            int mid = st+(end-st)/2;
            fun(ind,ans,st,mid);
            fun(ind,ans,mid+1,end);
            merge(ind,ans,st,mid,end);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<array<int,2>> ind(n);
        for(int i=0;i<n;i++){
            ind[i][0] = nums[i];
            ind[i][1] = i;
        }
        
        vector<int> ans(n,0);
        fun(ind,ans,0,n-1);
        return ans;
    }
};