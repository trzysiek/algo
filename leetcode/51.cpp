class Solution {
public:
    bool possiblePlacementAtColumn(int col, int n, vector<string> board) {
        for (const auto& row : board)
            if (row[col] == 'Q')
                return false;
        for (int row = (int)board.size() - 1, c = col - 1; row >= 0 && c >= 0; row--, c--)
            if (board[row][c] == 'Q')
                return false;
        for (int row = (int)board.size() - 1, c = col + 1; row >= 0 && c < n; row--, c++)
            if (board[row][c] == 'Q')
                return false;
        return true;
    }
    
    string newRow(int queenColumn, int n) {
        string res {};
        for (int i = 0; i < queenColumn; ++i)
            res += '.';
        res += 'Q';
        for (int i = queenColumn + 1; i < n; ++i)
            res += '.';
        return res;
    }
    
    void print(vector<string> board) {
        for (const auto& row : board)
            cout << row << endl;
        cout << endl;
    }
    
    vector<vector<string>> solveRec(int level, int n, vector<string> board) {
        if (level == n)
            return vector<vector<string>> { board };
        
        vector<vector<string>> result;
        for (int i = 0; i < n; ++i) {
            if (possiblePlacementAtColumn(i, n, board)) {
                vector<string> newBoard {board};
                newBoard.push_back(newRow(i, n));
                auto tmpRes = solveRec(level + 1, n, newBoard);
                result.insert(result.end(), tmpRes.begin(), tmpRes.end());
            }
        }
        return result;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        return solveRec(0, n, {});
    }
};
