typedef long long ll;
class Solution {
public:
    vector<int> memLeak(int a, int b) {
        vector<int> ans;
        ll cur = 0;
        ll val = 1;
        
        while(1){
            cur++;
            if(a>=b){
                if(a-val>=0){
                    a = a-val;
                    val++;
                }
                else break;
            }
            else{
                if(b-val>=0){
                    b = b-val;
                    val++;
                }
                else break;
            }
        }
        
        ans.push_back(cur);
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};