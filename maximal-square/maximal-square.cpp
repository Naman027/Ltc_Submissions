class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
      int rows = matrix.size() ;
      if(rows == 0) return 0 ;
      int cols = matrix[0].size() ;
      
      int sum[rows][cols] ;
      vector<int> temp ;
      for(int i = 0 ; i< rows ; i++){
          for(int j = 0 ; j<cols ; j++){
              if(matrix[i][j] == '1'){
                  if(i-1>=0)
                  sum[i][j] = sum[i-1][j] + 1 ;
                  else
                      sum[i][j] = 1 ;
              }
              else
                  sum[i][j] = 0 ;
          }
      }
        
      for(int i = 0 ; i<rows ; i++){
          vector<int> heights ;
          for(int j = 0 ; j<cols ; j++)
              heights.push_back(sum[i][j]) ;
         int n = heights.size();
        stack<int> s ;
        int right[n],left[n];
        for(int i = 0 ; i< n ; i++){
            while(!s.empty() && heights[s.top()] > heights[i]){
                right[s.top()] = i ;
                s.pop() ;
            }
            s.push(i) ;
        }
        while(!s.empty()){
            right[s.top()] = n ;
            s.pop() ;
        }
        for(int i = n-1 ; i>=0 ; i--){
            while(!s.empty() && heights[s.top()] > heights[i]){
                left[s.top()] = i ;
                s.pop() ;
            }
            s.push(i) ;
        }
        while(!s.empty()){
            left[s.top()] = -1 ;
            s.pop() ;
        }
        int maxi = INT_MIN ;
        for(int i = 0 ; i< n ; i++){
            int mi = min(heights[i],right[i]-left[i]-1);
            maxi = max(maxi , mi*mi) ;
        }
        temp.push_back(maxi) ;
      }
        
        int mi = INT_MIN;
        for(int i = 0 ; i< temp.size() ; i++){
            mi = max(mi , temp[i]) ;
        }
        return mi ;
    }
};