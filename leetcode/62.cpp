class Solution {
public:
    int uniquePaths(int m, int n) {
        int DP[m][n];
        DP[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                DP[i][j] = 0;
                if (j > 0) DP[i][j] += DP[i][j-1];
                if (i > 0) DP[i][j] += DP[i-1][j];
            }
        }
        return DP[m-1][n-1];
    }
};
