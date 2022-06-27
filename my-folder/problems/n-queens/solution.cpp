class Solution {
public:
    vector<vector<string>> ans;
    bool check(vector<string> &board)
    {
       vector<pair<int,int>> v;
       for(int i=0;i<board.size();i++)
       {
           for(int j=0;j<board[i].length();j++)
           {
               if(board[i][j]=='Q')
               { 
                   v.push_back({i,j});
               }
           }
       } 
        for(int i=0;i<v.size();i++)
        {
            for(int j=i+1;j<v.size();j++)
            {
                if(v[i].first==v[j].first)
                {
                    return 0;
                }
                if(v[i].second==v[j].second)
                {
                    return 0;
                }
                if(abs(v[j].second-v[i].second)==abs(v[j].first-v[i].first))
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    void solve(vector<string> &board,int row)
    {
        if(!check(board) or row>board.size())
        {
            return;
        }
        if(row==board.size() and check(board))
        { 
            ans.push_back(board);
            return;
        }   
            for(int j=0;j<board[0].length();j++)
            {
                if(board[row][j]=='.')
                {
                    board[row][j]='Q'; 
                    solve(board,row+1); 
                    board[row][j]='.';
                }
            }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string str;
        for(int i=0;i<n;i++)
        {
            str.push_back('.');
        }
        for(int i=0;i<n;i++)
        {
            board[i]=str;
        }
        int row = 0;
        solve(board,row); 
        return ans;
    }
};