class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> nextgreater(10001,-1);
        stack<int> stk;

        for(int i=0;i<m;i++){
            while(!stk.empty() && stk.top()<nums2[i]){
                nextgreater[stk.top()] = nums2[i];
                stk.pop();
            } 
            stk.push(nums2[i]);
        }

        vector<int> ans(n,0);
        for(int i=0;i<n;i++) ans[i] = nextgreater[nums1[i]];
        return ans;

    }
};
