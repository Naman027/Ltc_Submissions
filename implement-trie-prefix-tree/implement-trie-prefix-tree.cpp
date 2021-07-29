class Trie {
public:
    /** Initialize your data structure here. */
    
    struct TrieNode{
        char val;
        int count;
        int endsHere;
        TrieNode* child[26];
    };
    
    TrieNode* root;
    
    TrieNode* getNode(int index){
        TrieNode* trieNode = new TrieNode();
        trieNode->val = 'a'+index;
        trieNode->count = 0;
        trieNode->endsHere = 0;
        for(int i=0;i<26;i++){
            trieNode->child[i] = NULL;
        }
        return trieNode;
    }
    
    Trie() {
        root = getNode('/'-'a');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        int n = word.size();
        for(int i=0;i<n;i++){
            int index = word[i]-'a';
            if(cur->child[index]==nullptr) cur->child[index] = getNode(index);
            cur->child[index]->count++;
            cur = cur->child[index];
        }
        cur->endsHere++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.size();
        TrieNode* cur = root;
        for(int i=0;i<n;i++){
            int index = word[i]-'a';
            if(cur->child[index]==nullptr) return false;
            cur = cur->child[index];
        }
        return (cur->endsHere > 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.size();
        TrieNode* cur = root;
        for(int i=0;i<n;i++){
            int index = prefix[i]-'a';
            if(cur->child[index] == nullptr) return false;
            cur = cur->child[index];
        }
        return (cur->count>0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */