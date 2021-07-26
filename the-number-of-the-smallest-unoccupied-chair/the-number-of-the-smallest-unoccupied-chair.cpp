class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int target) {
        int n = times.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        set<int> s;
        int cur = 0;
        int reqin = times[target][0];
        sort(times.begin(),times.end());
        for(auto v:times){
            int in = v[0];
            int out = v[1];
            int seat = -1;
            while(!pq.empty() && pq.top().first<=in){
                s.insert(pq.top().second);
                pq.pop();
            }
            
            if(s.size()>=1){
                seat = *(s.begin());
                s.erase(s.begin());
            }
            else{
                seat = cur;
                cur++;
            }
            
            pq.push({out,seat});
            if(in==reqin) return seat;
            
        }
        return 0;
    }
};