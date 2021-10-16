#define ll long long
class Solution {
public:
    ll count(vector<ll>&A,vector<ll>&B,ll x){
        ll res=0;
        ll j=B.size()-1;
        for(ll i=0;i<A.size();++i){
            while(j>=0&&A[i]*B[j]>x){
                j-=1;
            }
            res+=j+1;
        }
        return res;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ll n=nums1.size();
        ll m=nums2.size();
        vector<ll>A1,A2,B1,B2;
        for(int i=0;i<n;++i){
            if(nums1[i]<0){
                A1.push_back(-nums1[i]);
            }
            else{
                A2.push_back(nums1[i]);
            }
        }
        reverse(A1.begin(),A1.end());
        for(int i=0;i<m;++i){
            if(nums2[i]<0){
                B1.push_back(-nums2[i]);
            }
            else{
                B2.push_back(nums2[i]);
            }
        }
        reverse(B1.begin(),B1.end());
        int neg=A1.size()*B2.size()+A2.size()*B1.size();
        int s;
        if(k>neg){
            k-=neg;
            s=1;
        }
        else{
            k=neg-k+1;
            swap(B1,B2);
            s=-1;
        }
        ll left=0,right=10e10;  //10e10 is 10 to the power 10.
        while(left<right){
            ll mid=left+(right-left)/2;
            if(count(A1,B1,mid)+count(A2,B2,mid)>=k){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left*s;
    }
};
