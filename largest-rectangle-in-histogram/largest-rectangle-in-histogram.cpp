class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0) return 0;
        if(n==1) return heights[0];
        stack<int> s ;
        int right[n],left[n];
        for(int i = 0 ; i< n ; i++){
            while(!s.empty() && heights[s.top()] > heights[i]){
                right[s.top()] = i ;
                s.pop() ;
            }
            s.push(i) ;
        }
        while(!s.empty())
        {
            right[s.top()] = n ;
            s.pop() ;
        }
        for(int i = n-1 ; i>=0 ; i--)
        {
            while(!s.empty() && heights[s.top()] > heights[i])
            {
                left[s.top()] = i ;
                s.pop() ;
            }
            s.push(i) ;
        }
        while(!s.empty())
        {
            left[s.top()] = -1 ;
            s.pop() ;
        }
        int maxi = INT_MIN ;
        for(int i = 0 ; i< n ; i++)
        {
            maxi = max(maxi , heights[i]*((right[i]-left[i])-1)) ;
        }
        return maxi;
        
    }
};