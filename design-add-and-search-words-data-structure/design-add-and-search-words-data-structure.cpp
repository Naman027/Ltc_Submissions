class WordDictionary {
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
    
    WordDictionary() {
        root = getNode('/'-'a');
    }
    
    void addWord(string word) {
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
    
    bool search1(TrieNode* root1,string word,int index) {
        if(index==word.size()){
            return (root1->endsHere>0);
        }
        int n = word.size();
        TrieNode* cur = root1;
        for(int i=index;i<n;i++){
            int index = word[i]-'a';
            if(word[i]=='.'){
                bool ans = 0;
                for(int j=0;j<26;j++){
                    if(cur->child[j]!=nullptr)
                        if(search1(cur->child[j],word,i+1)) ans = 1;
                }
                return ans;
            }
            if(cur->child[index]==nullptr) return false;
            cur = cur->child[index];
        }
        return (cur->endsHere > 0);    
    }
    
    bool search(string word){
        return search1(root,word,0);
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */