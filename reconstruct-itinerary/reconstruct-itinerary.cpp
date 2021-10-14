class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> mp;
        
        int n=tickets.size();
        for(int i=0;i<n; i++){
            mp[tickets[i][0]].insert(tickets[i][1]);
        }
        
        vector<string> ans;
        stack<string> st;
        st.push("JFK");
        while(!st.empty()){
            string tp=st.top();
            
            if(mp[tp].size()==0){
                ans.push_back(tp);
                st.pop();    
            }
            else{
                auto it=mp[tp].begin();
                st.push(*it);
                mp[tp].erase(it);
                
            }
            
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};