class Solution
{
    public:
    void nextpermute(string & str) 
    {   
        int ind = -1;
        for(int i=str.length()-2;i>=0;i--)
        {
            if(str[i]<str[i+1])
            {  
                ind = i;
                break;
            }
        }
        for(int i=str.length()-1;i>=0;i--)
        {
            if(str[i]>str[ind])
            {
                swap(str[i],str[ind]);
                reverse(str.begin()+ind+1,str.end());
                break;
            }
        }
        return;
    }
    string getPermutation(int n, int k)
    {
        string str;
        for (int i = 0; i < n; i++)
        {
            str.push_back(i + '1');
        } 
        k--;
        while (k--)
        {    
            nextpermute(str);
        }
        return str;
    }
};