class Solution {
public:
    vector<vector<int>> ans;

    void dfs(int node,vector<vector<int>>& graph,int n,vector<int> cur){
        if(node==n-1){
            if(cur.size()>=1) ans.push_back(cur);
            return;          
        }

        for(int child:graph[node]){
            cur.push_back(child);
            dfs(child,graph,n,cur);
            cur.pop_back();
        }
    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        ans.clear();
        vector<int> cur;
        cur.push_back(0);
        dfs(0,graph,n,cur);
        return ans;
    }
};