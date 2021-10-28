

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int ans = 0,ind = 0;

        for(int i=1;i<=1e5;i++){
            while(!pq.empty() && pq.top()<i) pq.pop();
            int j = ind;
            while(j<n){
                if(events[j][0]==i) pq.push(events[j][1]),j++;
                else break;
            }
            ind = j;
            if(!pq.empty()){
                ans++;
                pq.pop();
            }
        }
        return ans;
    }
};


