class Solution {
public:
    int evalRPN(vector<string>& arr) {
        int n = arr.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(arr[i]=="+"){
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                st.push(n1+n2);
            }
            else if(arr[i]=="-"){
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                st.push(-n1+n2);
            }
            else if(arr[i]=="*"){
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                st.push(n1*n2);
            }
            else if(arr[i]=="/"){
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                st.push((int)n2/n1);
            }
            else{
                st.push(stoi(arr[i]));
            }
        }
        return st.top();
    }
};