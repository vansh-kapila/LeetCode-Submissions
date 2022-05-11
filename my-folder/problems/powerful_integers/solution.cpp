class Solution
{
    public:
        vector<int> powerfulIntegers(int x, int y, int bound)
        {
            set<int> a;
            set<int> b;
            if(x==1 and y==1 and bound>=2)
            {
                return {2};
            } 
            else if(x==1 and y==1)
            {   
                return {};
            }
            vector<int> ans;
            int yy = 1;
            do {
                a.insert(yy);
                yy = yy * x;
                if(x==1)
                {
                    break;
                }
            } while (yy <= bound);
            yy = 1;
            do {
                b.insert(yy);      
                yy = yy * y;
                if(y==1)
                {
                    break;
                }
            } while (yy <= bound);
            
            for(auto i:a)
            {
                for(auto j:b)
                {
                    if(i+j<=bound)
                    {
                        ans.push_back(i+j);
                    }
                }
            }
            set<int> store(ans.begin(),ans.end());
            ans.clear();
            for(auto i:store)
            {
                ans.push_back(i);
            }
            return ans;
        }
};