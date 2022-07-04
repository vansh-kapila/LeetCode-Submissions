class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        map<int,vector<int>> mp;
        int j = 0;
        for(auto &i:row)
        {
            i/=2;
            mp[i].push_back(j++);
        }
        int count = 0;
        for(int i=0;i<row.size()-1;i+=2)
        {
            if(row[i]==row[i+1])
            {
                continue;
            } 
            count++;  
            int x = mp[row[i]][1];
            int y = mp[row[i+1]][0];
            int z = mp[row[i+1]][1];
            swap(row[x],row[y]); 
            mp[row[z]]={min(x,z),max(x,z)}; 
        }
        return count;
    }
};