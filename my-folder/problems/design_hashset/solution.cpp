class MyHashSet {
public:
    vector<int> v;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(find(v.begin(),v.end(),key)==v.end()){
        v.push_back(key);}
    }
    
    void remove(int key) {
        if(find(v.begin(),v.end(),key)!=v.end()){
        v.erase(find(v.begin(),v.end(),key));}
    }
    
    bool contains(int key) {
        if(find(v.begin(),v.end(),key)!=v.end())
        {
            return 1;
        }
        return 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */