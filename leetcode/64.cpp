class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = (int)grid.size(),
            columns = (int)grid[0].size();
        vector<vector<int>> DP;
        vector<int> first_row { grid[0][0] };
        for (int i = 1; i < columns; ++i)
            first_row.push_back(first_row.back() + grid[0][i]);
        DP.push_back(first_row);
        for (int i = 1; i < rows; ++i) {
            vector<int> now_row { DP[i-1][0] + grid[i][0] };
            for (int j = 1; j < columns; ++j)
                now_row.push_back(min(now_row[j - 1], DP[i - 1][j]) + grid[i][j]);
            DP.push_back(now_row);
        }
        return DP[rows - 1][columns - 1];
    }
};
