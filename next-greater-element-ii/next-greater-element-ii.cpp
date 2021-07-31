class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        vector<int> left(2*n,-1);
        for(int i=0;i<2*n;i++){
            while(!st.empty() && nums[st.top()]<nums[i%n]){
                left[st.top()] = nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        
        for(int i=0;i<n;i++) ans[i] = left[i];
        return ans;
        
    }
};