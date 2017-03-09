class Solution {
public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int result = 0;
        recNQueens(0, n, result, board);
        return result;
    }
    
private:
    bool isValid(int row, int col, int n, vector<string> &board) {
        for (int i = 0; i < row; ++i)
            if (board[i][col] == 'Q')
                return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;
        return true;
    }
    
    void recNQueens(int level, int n, int &result, vector<string> &board) {
        if (level == n)
            ++result;
        for (int i = 0; i < n; ++i)
            if (isValid(level, i, n, board)) {
                board[level][i] = 'Q';
                recNQueens(level + 1, n, result, board);
                board[level][i] = '.';
            }
    }
};
