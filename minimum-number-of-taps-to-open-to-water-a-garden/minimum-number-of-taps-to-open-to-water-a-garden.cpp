class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> currTaps;
        bool isGardenCovered = false;
        
        for(int i = 0; i < ranges.size() && !isGardenCovered; i++){
            int start = max(i - ranges[i], 0), end = i + ranges[i];            
            if(ranges[i] > 0 && currTaps.empty())
                currTaps.push_back({start,end});
            else if(ranges[i] > 0 && end > currTaps.back().second){
                while(!currTaps.empty() && start <= currTaps.back().first)
                    currTaps.pop_back();
                if(currTaps.empty())
                    currTaps.push_back({start, end});
                else if(start <= currTaps.back().second)
                    currTaps.push_back({currTaps.back().second, end});
            }
            isGardenCovered = !currTaps.empty() && currTaps.back().second >= n;
        }
        return isGardenCovered ? currTaps.size() : -1;
    }
};