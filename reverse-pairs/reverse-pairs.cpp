class Solution {
public:
    int merge(vector<int>& a,vector<int>& temp,int left,int mid,int right){
        int i,j,k;
        int inversions = 0;
        
        i = left;
        j = mid;
        k = left;                                        

        while((i<=mid-1) && (j<=right)){
            if((long long)a[i]<=(long long)2*(long long)a[j]) i++;
            else{
                j++;
                inversions+=(mid-i);
            }
        }
        
        i = left;
        j = mid;
        k = left;  
        while((i<=mid-1) && j<=right){
            if(a[i]<=a[j]) temp[k++] = a[i++];
            else{
                temp[k++] = a[j++];
            }
        }
        
        while(i<=mid-1) temp[k++] = a[i++];
        while(j<=right) temp[k++] = a[j++];

        for(int i=left; i<=right; i++) a[i] = temp[i];
        return inversions;
    }

    int mergeSort(vector<int>& a,vector<int>& temp,int left,int right){
        int mid, inversions = 0;
        if(right>left){
            mid = (left+right)/2;
            inversions+=mergeSort(a,temp,left,mid);
            inversions+=mergeSort(a,temp,mid+1,right);
            inversions+=merge(a,temp,left,mid+1,right);
        }
        //cout << left << " " << right << " " << inversions << endl;
        return inversions;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        return mergeSort(nums,temp,0,n-1); 
    }
};