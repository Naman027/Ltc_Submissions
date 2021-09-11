class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int i,n=deliciousness.size();
        unordered_map<int,int>m;
        int ans=0,mod = 1e9+7,ma=0;
        for(i=0;i<n;i++)
            ma=max(ma,deliciousness[i]);
        int p=1;
        while(p<=ma)
        {
            p*=2;
        }
        for(i=0;i<n;i++)
        {
            int x=1,c=0;
            while(x<=p)
            {
                c+=m[x-deliciousness[i]];
                x*=2;    
            }
            
            ans = (ans%mod+c%mod)%mod;
            m[deliciousness[i]]++;
        }
        return ans;
    }
};