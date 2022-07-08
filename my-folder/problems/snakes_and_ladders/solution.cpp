class Solution
{
    public:
        int snakesAndLadders(vector<vector < int>> &board)
        {
            vector<int> arr;
            for (int i = board.size() - 1; i >= 0; i--)
            {
                vector<int> v;
                for (int j = 0; j < board[i].size(); j++)
                {
                    v.push_back(board[i][j]);
                }
                if ((board.size()-1-i) % 2)
                {
                    reverse(v.begin(), v.end());
                }
                for (auto i: v)
                {
                    arr.push_back(i);
                }
            }
            for(int i=0;i<6;i++)arr.push_back(-1);
            queue<int> q;
            q.push(0);
            int moves = 0;
            vector<bool> vis(arr.size() + 1, 0);
            vis[0]=1;
            while (!q.empty())
            {
                moves++;
                vector<int> v;
                while (!q.empty())
                {
                    auto it = q.front();
                    q.pop();
                    for (int i = 1; i <= 6; i++)
                    {
                        int j = it + i;
                        if (arr[j] != -1)
                        {
                            j = arr[j] - 1;
                        }
                        if (j >= board.size()*board.size()-1)
                        {
                            return moves;
                        }
                        if(vis[j]!=1)
                        {
                            vis[j]=1;
                            v.push_back(j);
                        }
                    }
                }
                for(auto i:v)
                {
                    q.push(i);
                }
            }
            return -1;
        }
};