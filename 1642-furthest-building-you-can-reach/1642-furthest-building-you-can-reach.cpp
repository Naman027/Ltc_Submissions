class Solution {
public:

    bool check(int mid,vector<int>& heights,int bricks,int ladders){
        priority_queue<int> pq;
        for(int i=1;i<=mid;i++){
            if(heights[i]>heights[i-1])
                pq.push(heights[i]-heights[i-1]);
        }
        long long int cur = 0;
        while(!pq.empty()){
            if(ladders==0){
                cur+=(long long int)pq.top();
            }
            else ladders--;
            pq.pop();
        }
        return (cur<=bricks);
    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int l = 0, r = n-1;
        while(r-l>1){
            int mid = (l+r)/2;
            if(check(mid,heights,bricks,ladders)){
                l = mid;
            }
            else r = mid-1;
        }      

        if(check(r,heights,bricks,ladders)) return r;
        return l;
    }
};
