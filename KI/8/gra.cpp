#include <iostream>
using namespace std;

int DP[2001][2001]; // result for interval [a, b)
int sum;

int main() {
    int n;
    int t[2001];

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        DP[i][i + 1] = t[i];
        sum += t[i];
    }
    
    for (int int_l = 2; int_l <= n; ++int_l) { // internal_length
        for (int i = 0; i < n - int_l + 1; ++i) {
            DP[i][i + int_l] = max(t[i] - DP[i + 1][i + int_l],
                                   t[i + int_l - 1] - DP[i][i + int_l - 1]);
        }
    }
    cout << (sum-DP[0][n])/2 + DP[0][n] << " " << (sum-DP[0][n])/2 << endl;
}
