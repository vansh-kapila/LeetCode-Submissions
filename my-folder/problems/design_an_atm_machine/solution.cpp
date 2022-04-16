class ATM {
public:
    unordered_map<int,long long> m;
    vector<int> v={20,50,100,200,500};
    ATM() {
        
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<banknotesCount.size();i++)
        {
            m[i]+=banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ret;
        for(int j=4;j>=0;j--)
        {      
           // cout<<amount<<endl;
               long long notes = amount/v[j];
               ret.push_back(min(notes,m[j]));
               amount = amount-v[j]*min(notes,m[j]);
        }  
        if(amount==0)
        {   reverse(ret.begin(),ret.end());
            for(int i=0;i<=4;i++)
            {
                m[i]=m[i]-ret[i];
            }
            return ret; 
        } 
            vector<int> ans;
            ans.push_back(-1);
            return ans; 
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
