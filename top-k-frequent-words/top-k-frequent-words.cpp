class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        map<string,int> freq;
        for(string s:words) freq[s]++;

        vector<pair<int,string>> a;
        for(auto i:freq){
            a.push_back({i.second,i.first});
        }

        auto comp = [&](const pair<int,string>& a,const pair<int,string>& b) -> bool {
            if(a.first>b.first) return 1;
            else if(a.first<b.first) return 0;
            else{
                return a.second<b.second;
            }
        };

        sort(a.begin(),a.end(),comp);
        vector<string> ans;
        for(int i=0;i<k;i++) ans.push_back(a[i].second);
        return ans;
    }
};