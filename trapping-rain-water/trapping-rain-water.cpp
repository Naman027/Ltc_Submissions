class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        if(n==0) return 0;
        if(n==1) return 0;
        int lmin=0;
        int lmax[n];
        memset(lmax,0,sizeof(lmax));
        lmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
             lmax[i]=max(lmax[i+1],height[i]);  
        }
        for(int i=0;i<n;i++){
            lmin=max(lmin,height[i]);
            ans+=(min(lmin,lmax[i])-height[i]);               
        }
        
        return ans;
    }
};