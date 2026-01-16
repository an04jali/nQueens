class Solution {
public:

bool check(int n, vector<string>& board, int i, int j)
{
    // upper left diagonal , no queen should be present
    int row = i, col = j;
    while (row > -1 && col > -1)
    {
        if (board[row][col] == 'Q')
            return 0;
        row--, col--;
    }

    // upper right diagonal koi queen should not be present
    row = i, col = j;
    while (row > -1 && col < n)
    {
        if (board[row][col] == 'Q')
            return 0;
        row--, col++;
    }

    return 1; // ✅ FIX: return loop ke bahar hona chahiye
}



void find(int row, int n, vector<vector<string>>& ans,
          vector<string>& board, vector<bool>& column)
{
    // base condition
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    // put queen at any n position
    for (int j = 0; j < n; j++)
    {
        // agr column = 0 means no queen if present = 1
        if (column[j] == 0 && check(n, board, row, j))
        {
            column[j] = 1;
            board[row][j] = 'Q';

            find(row + 1, n, ans, board, column);

            // 🔴 FIX: backtracking (queen hatao)
            board[row][j] = '.';
            column[j] = 0;
        }
    }
}



vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans; // 2d vector having string value
    vector<string> board(n);    // n sized

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i].push_back('.'); // sb jgh pehle dot hi rhega we will fill

    vector<bool> column(n, 0); // ek n sized , initialized by 0

    find(0, n, ans, board, column);
    // 0 = row 0

    return ans; // ✅ FIX: missing return
}
};
