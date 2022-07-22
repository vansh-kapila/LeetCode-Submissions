class Solution{
public:
	int lengthLongestPath(string input){
		 stringstream ss(input);
         string data; 
         map<int,int> mp;
         int res = 0;
		 
         while(getline(ss, data, '\n'))
         { 
             int numTabs  = 0; 
			 
             while(data[numTabs] == '\t') numTabs++;
			 
             if(numTabs == 0)
                 mp[numTabs] = data.size(); 
             else { 
                 mp[numTabs] = mp[numTabs - 1] + 1 + data.substr(numTabs).size(); 
			 }
			  
             if(data.find('.') != string :: npos)
                 res = max(res, mp[numTabs]);
         }
		 
        return res;
    }
};
