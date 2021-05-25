class Solution {
public:
    bool ans = 0;
    void dfs(int node,vector<vector<int>>& rooms,set<int>& s){
        if(s.size()==0){
            ans = true;
            return;
        }
        //cout << s.size() << endl;
        if(s.find(node)==s.end()) return;
        s.erase(node);
        if(s.size()==0){
            ans = true;
            return;
        }
        for(auto child:rooms[node]){
            dfs(child,rooms,s);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        set<int> s;
        for(int i=0;i<n;i++) s.insert(i);
        ans = 0;
        dfs(0,rooms,s);
        return ans;
    }
};