class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> ans;
        set<int> prev;
        ans.insert(arr[0]);
        prev.insert(arr[0]);
        int n = arr.size();
        for(int i=1;i<n;i++){
            set<int> cur;
            cur.insert(arr[i]);
            ans.insert(arr[i]);
            for(auto a:prev){
                cur.insert(a|arr[i]);
                ans.insert(a|arr[i]);
            }
            prev = cur;
        }
        return ans.size();
    }
};