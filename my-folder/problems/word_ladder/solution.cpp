class Solution {
public:
    unordered_map<string,int> visited;
    unordered_map<string,int> ind;
    unordered_set<string> ss;
    
    
    int bfs(string str,string ptr)
    {   int ans = 1; 
        ind[str]=1;
        queue<string> q;
        q.push(str); 
        while(!q.empty())
        {
            string x = q.front();
            q.pop(); 
            ans=ind[x]+1;
            if(x==ptr)
            {
                return ind[x];           
            } 
            for(int i=0;i<x.length();i++)
            {    string temp = x;
                 for(int j=0;j<26;j++)
                 {
                     char c = (char)('a'+j);
                     temp[i]=c;
                     if(ss.find(temp)!=ss.end())
                     {
                         q.push(temp);
                         ss.erase(ss.find(temp));
                         ind[temp]=ans;
                     }
                 }
            }
        }
         return 0;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        for(auto i:wordList)
        {
            ss.insert(i);
        }
        ss.erase(beginWord);
        int ans = bfs(beginWord,endWord);  
        return ans;
    }
};