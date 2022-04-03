class Encrypter {
public:
    unordered_map<char,string> m;
    unordered_map<string,int> mm;
    unordered_map<string,vector<char>> mm2;
    vector<string> v;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i=0;i<keys.size();i++)
        {
            m[keys[i]]=values[i];
        }
        for(int i=0;i<keys.size();i++)
        {
            mm[values[i]]++;
        }
        for(int i=0;i<keys.size();i++)
        {
            mm2[values[i]].push_back(keys[i]);
        }
        for(auto i:dictionary)
        {
            v.push_back(i);
        }
    }
    
    string encrypt(string word1) {
        
        string ans;
        for(int i=0;i<word1.length();i++)
        {
            ans.append(m[word1[i]]);
        }
        return ans;
    }
    
    int decrypt(string word2) {
        int ans = 0; 
        for(int i=0;i<v.size();i++)
        {
            string x;
            string word1 = v[i];
            x=encrypt(word1);
            if(x==word2)
            {
                ans++;
            }
        }
        return ans;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */