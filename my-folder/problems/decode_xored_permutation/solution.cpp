class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int xxor = 0;
        for(int i=1;i<=encoded.size()+1;i++)
        {
            xxor = (xxor^i);
        }
        
        for(int i=1;i<encoded.size();i+=2)
        {
            xxor = (xxor^encoded[i]);
        }
        
        vector<int> v;
        v.push_back(xxor);
        for(auto &i:encoded)
        {
            v.push_back((xxor^i));
            xxor = v.back();
        }
        return v;
    }
};