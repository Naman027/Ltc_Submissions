class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& words) {
        int n = words.size();
        int len = beginWord.size();
        unordered_set<string> uset(words.begin(), words.end());
        if(!uset.count(endWord)) return 0;
        queue<string> q;
        int ans = 1;
        q.push(beginWord);
        while(!q.empty()) {
            int l = q.size();
            while(l--){
                string front = q.front();
                q.pop();
                if(front==endWord) return ans;
                for(int i=0;i<len;i++){
                    string word = front;
                    for(int j=0;j<26;j++){
                        word[i] = 'a'+j;
                        if(uset.count(word)){ 
                            q.push(word);
                            uset.erase(word);
                        }
                    }
                }
            }
            ans++;
        }   
        return 0;        
    }
};