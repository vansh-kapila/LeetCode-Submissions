class MyHashMap {
public:
    
    vector<pair<int,int>> v;
    MyHashMap() {
    }
    
    void put(int key, int value) {
        v.push_back(make_pair(key,value));
    }
    
    int get(int key) {
        for(int i=v.size()-1;i>=0;i--)
        {
            if(v[i].first==key)
            {
                return v[i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first==key)
            {
                v[i].first=1000000007;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */