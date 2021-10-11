
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(asteroids[i]);
            }
            else{
                bool f = 1;
                while(!st.empty()){
                    int top = st.top();
                    st.pop();
                    if(abs(top)<asteroids[i] && top<0 && asteroids[i]>0){
                        continue;
                    }
                    else if(abs(top)==asteroids[i] && top<0 && asteroids[i]>0){
                        f = 0;
                        break;
                    }
                    else if(abs(top)>asteroids[i] && top<0 && asteroids[i]>0){
                        f = 0 ;
                        st.push(top);
                        break;
                    }
                    else{
                        st.push(top);
                        break;
                    }
                }
                if(f) st.push(asteroids[i]);
            }
        }

        vector<int> ans;
        while(!st.empty()) ans.push_back(st.top()),st.pop();
        return ans;
    }
};
