class Solution {
public:
    long long countVowels(string word) {
        long long ans = 0;
        int n = word.size();
        vector<char> cc = {'a','e','i','o','u'};
        for(int i=0;i<word.size();i++){
            bool f = 0;
            for(int j=0;j<5;j++){
                if(word[i]==cc[j]) f = 1;
            }
            if(f){
                long long v = (long long)(i+1)*(long long)(n-i);
                ans+=v;
            }
        }
        return ans;
    }
};