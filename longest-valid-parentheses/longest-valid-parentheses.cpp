class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> ch,ind;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                ch.push('(');
                ind.push(i);
            }
            else{
                if(ch.size()>=1){
                    ind.pop();
                    ch.pop();
                    if(ind.size()==0){
                        ans = max(ans,i+1);
                    }
                    else ans = max(ans,i-ind.top());
                }
                else{
                    ind.push(i);
                }
            }
        }
        return ans;
    }
};

/*

)()(
-1 + 1 -1 +1 



*/