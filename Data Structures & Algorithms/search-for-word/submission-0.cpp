class Solution {
public:
    bool rec(vector<vector<char>>& board, string ds,
             int m, int n,
             vector<vector<int>>& vis,
             string& word)
    {
        if(ds == word)
            return true;

        if(ds.size() >= word.size())
            return false;

        vis[m][n] = 1;

        string temp = ds + board[m][n];

        if(temp == word)
            return true;

        bool up = false, down = false, left = false, right = false;

        if(m > 0 && !vis[m-1][n])
            up = rec(board, temp, m-1, n, vis, word);

        if(m + 1 < board.size() && !vis[m+1][n])
            down = rec(board, temp, m+1, n, vis, word);

        if(n > 0 && !vis[m][n-1])
            left = rec(board, temp, m, n-1, vis, word);

        if(n + 1 < board[0].size() && !vis[m][n+1])
            right = rec(board, temp, m, n+1, vis, word);

        vis[m][n] = 0;

        return up || down || left || right;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                vector<vector<int>> vis(rows, vector<int>(cols, 0));

                if(rec(board, "", i, j, vis, word))
                    return true;
            }
        }

        return false;
    }
};