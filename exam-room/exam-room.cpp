class ExamRoom {
public:
    set<int> sit;
    int maxN;
    ExamRoom(int n) {
        sit.clear();
        maxN = n-1;
    }
    
    int seat() {
        if(sit.size()==0){
            sit.insert(0);
            return 0;
        }        
        
        auto it = *sit.begin();
        
        int prev = 0;
        int ma = 0, ans = 0;
        if(it>ma){
            ma = it;
            ans = 0;
        }
        for(auto i:sit){
            int ss = (prev+i)/2;
            if(prev!=i){
                if(ss-prev>ma){
                    ma = ss-prev;
                    ans = ss;
                }
            }
            prev = i;
        }
        
        if(maxN-prev>ma){
            ans = maxN;
        }
        else{
            int ss = (maxN+prev)/2;
            if(ss-prev>ma){
                ma = ss-prev;
                ans = ss;
            }
        }
        
        sit.insert(ans);
        return ans;
    }
    
    void leave(int p) {
        auto it = sit.find(p);
        if(it==sit.end()){
            cout << "Out";
            return;
        }
        sit.erase(it);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */