class StockPrice {
public:
    int prev,pr;
    set<pair<int,int>> vals;
    map<int,int> mp;
    StockPrice() {
        mp.clear();
        vals.clear();
        prev = 0;
        pr = 0;
    }
    
    void update(int timestamp, int price) {
        if(timestamp>=prev){
            prev = timestamp;
            pr = price;
        }
        
        if(mp.find(timestamp)!=mp.end()){
            int prevprice = mp[timestamp];
            auto it = vals.find({prevprice,timestamp});
            vals.erase(it);
            mp[timestamp] = price;
            vals.insert({price,timestamp});
        }
        else{
            mp[timestamp] = price;
            vals.insert({price,timestamp});
        }
        
    }
    
    int current() {
        return pr;        
    }
    
    int maximum() {
        auto it = vals.end();
        it--;
        return it->first;
    }
    
    int minimum() {
        auto it = vals.begin();
        return it->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */