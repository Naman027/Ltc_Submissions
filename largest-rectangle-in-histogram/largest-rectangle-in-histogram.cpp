class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0) return 0;
        if(n==1) return heights[0];
        int ans=0;
        stack<int> st;
        int i=0;
        while(i<n){
            if(st.empty() || heights[i]>=heights[st.top()]){
                st.push(i);
                i++;
            }
            else{
                int cur=st.top();
                st.pop();
                if(st.empty()){
                    ans=max(ans,i*heights[cur]);
                }   
                else{
                    ans=max(ans,heights[cur]*(i-1-st.top()));
                }
                
            }
        }
        
        while(!st.empty()){
            int cur=st.top();
            st.pop();
            if(st.empty()){
                 ans=max(ans,i*heights[cur]);
            }   
            else{
                 ans=max(ans,heights[cur]*(i-1-st.top()));
            }   
        }
        
        return ans;
    }
};