class Solution {
public:
    string smallestSubsequence(string s, int k, char l, int r) {
        string res(k, l); 
        if(k == r) return res;
        
        int n = 0;
        for(char& c : s) if(c == l) n++;
        
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            while(!st.empty() && st.top() > s[i] && (s.size() - i + st.size()-1 >= k) && (st.top() != l || n > r)){
                if(st.top() == l) r++;
                st.pop();
            }
            if(st.size() < k){
                if(s[i] == l){
                    st.push(s[i]);
                    r--;
                }
                else if(k > st.size() + r) st.push(s[i]);
            }
            if(s[i] == l) n--;
        }
        
        while(!st.empty()){
            res[--k] = st.top();
            st.pop();
        }
        
        return res;
    }
};