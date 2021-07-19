class Solution {
public:
    int getMaxLen(vector<int>& a) {
        int n = a.size();
        int st = -1, end = -1;
        int zeroind = -1,odc = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                int lastlen = i-1-zeroind;
                if(st==-1 && end==-1){
                    ans = max(ans,lastlen);
                }
                else if(end==-1){
                    ans = max(ans,st-1-zeroind);
                    ans = max(ans,i-1-st);
                }
                else{
                    if(odc%2==0) ans = max(ans,lastlen);
                    else{
                        ans = max(ans,i-st-1);
                        ans = max(ans,end-1-zeroind);
                    }
                }
                st = -1, end =-1;
                odc = 0;
                zeroind = i;
            }
            else{
                if(a[i]<0){
                    if(st==-1){
                        st = i;
                    }
                    else{
                        end = i;
                    }
                    odc++;
                }
                int lastlen = i-zeroind;
                if(st==-1 && end==-1){
                    ans = max(ans,lastlen);
                }
                else if(end==-1){
                    ans = max(ans,st-1-zeroind);
                    ans = max(ans,i-st);
                }
                else{
                    if(odc%2==0) ans = max(ans,lastlen);
                    else{
                        ans = max(ans,i-st);
                        ans = max(ans,end-1-zeroind);
                    }
                }
            }
            //cout << i << " " << st << " " << end << " " << ans << endl;
        }
        return ans;
    }
};