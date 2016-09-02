#include <iostream>
using namespace std;

const int INF = (1 << 30); // guard - any of t[i] will be smaller in absolute value

int main() {
    int n;
    int t[1000];
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> t[i];
    for (int i = 0; i < n; ++i) {
        int max = -INF;
        int best;
        for (int j = 0; j < n; ++j) {
            if (t[j] > max) best = j, max = t[j];
        }
        t[best] = -INF + 1;
        cout << max << " ";
    }
}
