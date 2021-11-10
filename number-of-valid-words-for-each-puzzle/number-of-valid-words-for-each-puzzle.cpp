class Trie {
    Trie* chars[26] {};    
    int endsHere = 0;      
public:
    void insert(set<char> s) {
		if(size(s) > 7) return;
        Trie* cur = this;
        for(auto c : s) {
            if(!cur -> chars[c - 'a']) 
                cur -> chars[c - 'a'] = new Trie();            
            cur = cur -> chars[c - 'a'];
        }
        cur -> endsHere++;
    }
    
    int dfs(string& s, Trie* cur, bool hasFirst = false) {
        int ans = hasFirst ? cur -> endsHere : 0;   
        for(auto c : s) 
            if(cur -> chars[c-'a'])                 
                ans += dfs(s, cur -> chars[c-'a'], hasFirst | c == s[0]);
        return ans;
    }
};

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& W, vector<string>& P) {
        vector<int> ans(size(P));
        Trie* root = new Trie();
        for(auto& word : W) 
            root -> insert(set<char>(begin(word), end(word)));  
        for(int i = 0; auto& puzzle : P) 
            ans[i++] = root -> dfs(puzzle, root);
        return ans;
    }
};