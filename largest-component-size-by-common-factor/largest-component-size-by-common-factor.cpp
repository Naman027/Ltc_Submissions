class Solution {
public:
    vector<int> par,ranki;

    int findPar(int node){
        if(node==par[node]) return node;
        return par[node] =  findPar(par[node]);  //Path Compression
    }

    void Union(int a,int b){
        a = findPar(a);
        b = findPar(b);
        // Union By Rank
        if(a==b) return;
        if(ranki[a]<ranki[b]){
            par[a] = b;
            ranki[b]+=ranki[a];
        }
        else if(ranki[a]>ranki[b]){ 
            par[b] = a;
            ranki[a]+=ranki[b];
        }
        else{
            par[b] = a;
            ranki[a]+=ranki[b];
        }
    }

    int size(int node){
        return ranki[findPar(node)];
    }

    vector<int> spf;
    void sieve(int n) { 
        spf.resize(n);
        for (int i = 2; i < n; ++i) spf[i] = i;
        for (int i = 2; i * i < n; i++) {
            if (spf[i] != i) continue; 
            for (int j = i * i; j < n; j += i)
                if (spf[j] > i) spf[j] = i; 
        }
    }

    vector<int> getPrimeFactors(int n) { 
        vector<int> factors;
        while (n > 1) {
            factors.push_back(spf[n]);
            n /= spf[n];
        }
        return factors;
    }

    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int maxEl = *max_element(nums.begin(),nums.end());
        sieve(maxEl+1);

        par = vector<int>(maxEl+1);
        ranki = vector<int>(maxEl+1);
        for(int i=0; i<maxEl+1;i++) par[i] = i,ranki[i] = 1;

        for(int x:nums){
            for(int f: getPrimeFactors(x)){
                Union(x,f);
            }
        }
        int ans = 1;
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[findPar(x)]++;
            ans = max(ans,mp[findPar(x)]);
        }

        return ans;

    }
};