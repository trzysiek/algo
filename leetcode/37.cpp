#include <iostream>
#include <vector>

class Sudoku {
  public:
    using Board = std::vector<std::vector<char>>;
    const static int BOARD_SIZE = 9;

  private:
    Board test = {
        {'5', '3', '.',  '.', '7', '.',  '.', '.', '.'},
        {'6', '.', '.',  '1', '9', '5',  '.', '.', '.'},
        {'.', '9', '8',  '.', '.', '.',  '.', '6', '.'},
        {'8', '.', '.',  '.', '6', '.',  '.', '.', '3'},
        {'4', '.', '.',  '8', '.', '3',  '.', '.', '1'},
        {'7', '.', '.',  '.', '2', '.',  '.', '.', '6'},
        {'.', '6', '.',  '.', '.', '.',  '2', '8', '.'},
        {'.', '.', '.',  '4', '1', '9',  '.', '.', '5'},
        {'.', '.', '.',  '.', '8', '.',  '.', '7', '9'}
    };

  public:
    Sudoku(const Board& board) : board(board) {
        check_board_consistency();
    }
    Sudoku() : board(test) {}
    void solve();
    friend std::ostream& operator<<(std::ostream &out, const Sudoku &s);

  private:
    Board board;

    void check_board_consistency() {
        bool invalid_sizes = board.size() != BOARD_SIZE;
        for (auto &row : board)
            if (row.size() != BOARD_SIZE)
                invalid_sizes = true;

        if (invalid_sizes)
            throw std::runtime_error("Invalid size");

        // TODO check if board is OK
    }

};

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
    }
};

std::ostream& operator<<(std::ostream &out, const Sudoku &s) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            out << s.board[i][j] << " ";
            if (j == 2 || j == 5)
                out << "|";
        }

        if (i == 2 || i == 5) {
            out << std::endl;
            for (int j = 0; j < 19; ++j)
                out << "-";
        }
        out << std::endl;
    }
}

int main() {
    Sudoku s;
    std::cout << s << std::endl;
}
