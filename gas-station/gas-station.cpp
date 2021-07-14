class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totcost = 0, totgas = 0;
        for(int i=0;i<n;i++){
            totcost+=cost[i];
            totgas+=gas[i];
        }
        
        if(totcost>totgas) return -1;
        int curdel = 0,start = 0;
        for(int i=0;i<n;i++){
            int diff = gas[i]-cost[i];
            if(curdel+diff<0){
                start = i+1;
                curdel = 0;
            }
            else{
                curdel+=diff;
            }
        }
        
        return start;
        
    }
};