class Solution
{
    public:
        bool isValidSudoku(vector<vector < char>> &board)
        {
            unordered_map<char, int> mp;
            for (int i = 0; i < board.size(); i++)
            {
                mp.clear();
                for (int j = 0; j < board[0].size(); j++)
                {
                    mp[board[i][j]]++;
                    if (board[i][j] != '.'
                        and mp[board[i][j]] >= 2)
                    {
                        return 0;
                    }
                }
            }

            for (int i = 0; i < board[0].size(); i++)
            {
                mp.clear();
                for (int j = 0; j < board.size(); j++)
                {
                    mp[board[j][i]]++;
                    if (board[j][i] != '.'
                        and mp[board[j][i]] >= 2)
                    {
                        return 0;
                    }
                }
            }

            for (int i = 0; i < 9; i += 3)
            {
                for (int j = 0; j < 9; j += 3)
                {
                    mp.clear();
                    for (int k = 0; k < 3; k++)
                    {
                        for (int l = 0; l < 3; l++)
                        {
                            mp[board[k + i][l + j]]++;
                            if (board[k + i][l + j] != '.'
                                and mp[board[k + i][l + j]] >= 2)
                            {
                                return 0;
                            }
                        }
                    }
                }
            }
            return 1;
        }
};