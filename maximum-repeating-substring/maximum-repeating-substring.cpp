class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        int m = word.size();

        int ans = 0;
        string cur;
        for(int i=1;i<=100;i++){
            cur+=word;
            if(sequence.find(cur)!=string::npos){
                ans = i;
            }
        }

        return ans;

    }
};