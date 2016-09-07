#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; // nr of holes
    int k; // nr of benches
    int m; // nr of worms
    int t[100000];

    cin >> n >> k >> m;
    for (int i = 0; i < m; ++i)
        cin >> t[i];

    int diff[100000];
    for (int i = 0; i < m - 1; ++i)
        diff[i] = t[i + 1] - t[i];

    int res = t[m - 1] - t[0] + 1;
    sort(diff, diff + m - 1);

    for (int i = m - 2, how_many = 1; i >= 0 && how_many < k; i--, how_many++)
        res -= diff[i] - 1;

    cout << res << endl;
}
