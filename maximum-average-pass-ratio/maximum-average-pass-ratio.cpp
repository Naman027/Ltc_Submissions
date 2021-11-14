class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<pair<double,pair<double,double>>> pq;
        
        for(int i=0;i<n;i++){
            double a = classes[i][0]*1.0;
            double b = classes[i][1]*1.0;
            double v = (b-a)/(b*(b+1.0));
            pq.push({v,{a,b}});
        }

        while(extraStudents){
            pair<double,pair<double,double>> tp = pq.top();
            pq.pop();

            double a = tp.second.first+1.0;
            double b = tp.second.second+1.0;

            double v = (b-a)/(b*(b+1.0));
            pq.push({v,{a,b}});
            extraStudents--;
        }

        double ans=0.0;
        while(!pq.empty()){
            ans+=(pq.top().second.first)/pq.top().second.second;
            pq.pop();
        }

        return ans/n*1.0;
    }
};