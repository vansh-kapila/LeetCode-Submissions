class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        map<pair<int,int>,int> m;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(j>0 and board[i][j-1]==1)
                {
                    m[{i,j}]++;
                }
                if(i>0 and board[i-1][j]==1)
                {
                    m[{i,j}]++;
                }
                if(j<board[0].size()-1 and board[i][j+1]==1)
                {
                    m[{i,j}]++;
                }
                if(i<board.size()-1 and board[i+1][j]==1)
                {
                    m[{i,j}]++;
                }
                if(i<board.size()-1 and j<board[0].size()-1 and board[i+1][j+1]==1)
                {
                    m[{i,j}]++;
                }
                if(j>0 and i>0 and board[i-1][j-1]==1)
                {
                    m[{i,j}]++;
                }
                if(i>0 and j<board[0].size()-1 and board[i-1][j+1]==1)
                {
                    m[{i,j}]++;
                } 
                if(i<board.size()-1 and j>0 and board[i+1][j-1]==1)
                {
                    m[{i,j}]++;
                }
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {   
                //cout<<m[{i,j}]<<' ';
                if(m[{i,j}]<2)
                {
                    board[i][j]=0;
                }
                if(board[i][j]==1 and (m[{i,j}]==2 or m[{i,j}]==3))
                {
                    board[i][j]=1;
                }
                if(m[{i,j}]>3)
                {
                    board[i][j]=0;
                }
                if(m[{i,j}]==3)
                {
                    board[i][j]=1;
                }
            }
        }
    }
};