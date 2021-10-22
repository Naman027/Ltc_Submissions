class Solution {
public:
    string frequencySort(string s) {
        int freq[256] = {0};
        for(char c:s) freq[c]++;
        
        vector<pair<int,char>> a;
        for(int i=0;i<256;i++){
            if(freq[i]) a.push_back({freq[i],i});
        }
        
        sort(a.begin(),a.end());
        string ans;
        for(int i=a.size()-1;i>=0;i--){
            int len = a[i].first;
            char c = (char)a[i].second;
            while(len--){
                ans.push_back(c);
            }
        }
        return ans;
    }
};