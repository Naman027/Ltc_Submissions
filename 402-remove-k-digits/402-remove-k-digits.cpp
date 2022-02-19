#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long long double

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string ans;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.size()==0) st.push((int)(num[i]-'0'));
            else{
                int top = st.top();
                int cur = num[i]-'0';
                if(top<=cur){
                    st.push(cur);
                }
                else{
                    while(!st.empty() && k){
                        int top = st.top();
                        if(top>cur){
                            k--;
                            st.pop();
                        }
                        else break;
                    } 
                    st.push(cur);
                }
            }
        }
                
        while(k--){
            st.pop();
        }
        bool nonZero = 0;
        while(!st.empty()){
            int top = st.top();
            char c = top+'0';
            ans.push_back(c);
            if(c!='0') nonZero = 1;
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        
        if(nonZero==1) ans.erase(0, ans.find_first_not_of('0'));
        else ans = "0";

        return ans;
    }
};
