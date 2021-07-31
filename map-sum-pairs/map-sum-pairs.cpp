class MapSum {
public:
    /** Initialize your data structure here. */
    
    struct TrieNode{
        int weight = 0;
        TrieNode* children[26]; 
    };
    
    TrieNode* root = NULL;
    
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* curr = root;
        int n = key.size();
        for(int i=0;i<n;i++){
            int ind = key[i] - 'a';
            if(curr->children[ind]==nullptr){
                curr->children[ind] = new TrieNode();
            }
            curr = curr->children[ind];
        }
        curr->weight = val;
    }
    
    int sum(string prefix) {
        TrieNode* curr= root;
        int n = prefix.size();
        for(int i=0;i<n;i++){
            int ind = prefix[i]-'a';
            if(curr->children[ind]==nullptr) return 0;
            curr = curr->children[ind];
        }
        return dfs(curr);
    }
    
    int dfs(TrieNode* curr){
        int sum = 0;
        for(int i=0;i<26;i++){
            if(curr->children[i]!=nullptr) sum+=dfs(curr->children[i]);
        }
        return sum+curr->weight;
    }
    
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */