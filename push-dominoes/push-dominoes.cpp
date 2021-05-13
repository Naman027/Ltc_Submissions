class Solution {
public:
    string pushDominoes(string dom) {
        stack<int> st;
        int n = dom.size();
        vector<int> suff(n,-1);
        vector<int> pref(n,-1);
        for(int i=0;i<n;i++){
            if(dom[i]=='.') st.push(i);
            else if(dom[i]=='L'){
                while(!st.empty()) suff[st.top()] = i, st.pop();
            }
            else{
                while(!st.empty()) st.pop();
            }
        }
        
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            if(dom[i]=='.') st.push(i);
            else if(dom[i]=='R'){
                while(!st.empty()) pref[st.top()] = i, st.pop();
            }
            else{
                while(!st.empty()) st.pop();
            }
        }
        
        for(int i=0;i<n;i++){
            if(dom[i]!='.') continue;
            int left = pref[i];
            int right = suff[i];
            if(left==-1 && right!=-1){
                dom[i] = 'L';
            }
            else if(left!=-1 && right==-1){
                dom[i] = 'R';
            }
            else if(left!=-1 && right!=-1){
                left = i-left;
                right = right-i;
                if(left>right) dom[i] = 'L';
                else if(left<right) dom[i] = 'R';
            }
        }
        return dom;
    }
};