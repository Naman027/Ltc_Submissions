class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        int n = pos.size();
        int mi = INT_MAX, ma = INT_MIN;
        for (int i = 0; i < n; i++){
            mi = min(mi,pos[i]);
            ma = max(ma,pos[i]);
        }
        sort(begin(pos), end(pos));
        int lo = 1,high = ma-mi;

        auto check = [&](int mid){
            int count = 0;
            for(int i=0;i<n;i++){
                int st = pos[i];
                int j = i;
                while(j<n && pos[j]-pos[i]<mid) j++;
                if(j!=n) count++;
                i = j-1;
            }
            return count>=(m-1);
        };
        int ans = -1;
        while(lo<=high){
            int mid = (lo+high)/2;
            //cout << mid << endl;
            if(check(mid)) ans =mid,lo = mid+1;
            else high = mid-1;
        }
        return ans;
    }
};

