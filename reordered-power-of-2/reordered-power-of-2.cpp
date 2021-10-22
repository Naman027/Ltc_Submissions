class Solution {
public:
    string sortedNum(int n ) {
        string str = to_string(n);
        sort(str.begin(), str.end());
        return str;
    }
    bool reorderedPowerOf2(int n) {
        string curr = sortedNum(n);
        for(int i=0; i<32; i++) {
            if(curr == sortedNum(1<<i)) return true;
        }
        return false;
    }
};