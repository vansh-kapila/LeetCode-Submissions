class Solution {
public: 
    bool solve(vector<vector<char>> &board,int i,int j,string &word,int n)
    {
        if(n==word.length())
        {
            return 1;
        } 
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size())
        {
            return 0;
        }
        if(board[i][j]!=word[n])
        {
            return 0;
        }
        char c = board[i][j];
        board[i][j]='0';
        bool ans = solve(board,i+1,j,word,n+1)||solve(board,i,j+1,word,n+1)||solve(board,i-1,j,word,n+1)||solve(board,i,j-1,word,n+1); 
        board[i][j]=c;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) { 
       
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {   
                if(solve(board,i,j,word,0))
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};