class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows_nr = (int)obstacleGrid.size();
        int col_nr  = (int)obstacleGrid[0].size();
        int DP[101][101];
        DP[0][0] = obstacleGrid[0][0] == 0;
        for (int i = 0; i < rows_nr; ++i)
            for (int j = 0; j < col_nr; ++j) {
                if (i == 0 && j == 0) continue;
                DP[i][j] = 0;
                if (obstacleGrid[i][j] == 1) 
                    continue;
                if (i > 0) DP[i][j] += DP[i-1][j];
                if (j > 0) DP[i][j] += DP[i][j-1];
            }
        return DP[rows_nr-1][col_nr-1];
    }
};
