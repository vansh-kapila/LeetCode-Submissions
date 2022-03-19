class Solution {
public:
    long long count(string &a, string &b)
{
    int m = a.length();
    int n = b.length();
    int x = m+1;
    int y = n+1;
    long long lookup[x][y];
    memset( lookup, 0, x*y*sizeof(long long) );

  
    for (int i = 0; i <= n; ++i)
        lookup[0][i] = 0;
  
    for (int i = 0; i <= m; ++i)
        lookup[i][0] = 1;
  
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++) 
        {
            if (a[i - 1] == b[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1] +
                               lookup[i - 1][j];
                 
            else 
                lookup[i][j] = lookup[i - 1][j];
        }
    }
 
    return lookup[m][n];
}

    long long maximumSubsequenceCount(string text, string pattern) {
        
        string a = text;
        string b = text; 
        a.push_back(pattern[1]);
        b.insert(b.begin(),pattern[0]);
        
        return max(count(a,pattern),count(b,pattern));
         
    }
};