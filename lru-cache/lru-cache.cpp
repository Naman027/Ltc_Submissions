class LRUCache {
public:
    int capacity;
    set<pair<int,int>> inside;
    map<int,int> mp,tim;
    int timer;
    LRUCache(int _capacity) {
        capacity = _capacity;
        inside.clear();
        tim.clear();
        mp.clear();
        timer = 0;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            int time = tim[key];
            int val = mp[key];
            auto it = inside.find({time,key});
            inside.erase(it);
            timer++;
            tim[key] = timer;
            inside.insert({timer,key});
            return val;
            //return 9;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(inside.size()==capacity){
            if(mp.find(key)!=mp.end()){
                mp[key] = value;
                int time = tim[key];
                auto it = inside.find({time,key});
                timer++;
                inside.erase(it);
                inside.insert({timer,key});
                tim[key] = timer;
            }
            else{
                auto it = inside.begin();
                int timm = it->second;
                auto mpit = mp.find(timm);
                mp.erase(mpit);
                inside.erase(it);
                timer++;
                inside.insert({timer,key});
                mp[key] = value;
                tim[key] = timer;
            }
        }
        else{
            if(mp.find(key)!=mp.end()){
                mp[key] = value;
                int time = tim[key];
                auto it = inside.find({time,key});
                timer++;
                inside.erase(it);
                inside.insert({timer,key});
                tim[key] = timer;
            }
            else{
                timer++;
                //cout << key << " " << value << endl;
                inside.insert({timer,key});
                mp[key] = value;
                tim[key] = timer;
            }
        }

    }
};