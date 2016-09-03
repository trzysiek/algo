#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int t[50001];

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> t[i];

    sort(t, t + n);
    t[n] = (1 << 30);
    int ile = 1, best = t[0], ilenow = 1;

    for (int i = 1; i <= n; ++i) {
        if (t[i] != t[i-1]) {
            if (ilenow > ile)
                ile = ilenow, best = t[i-1];
            ilenow = 1;
        }
        else ++ilenow;
    }
    cout << best << endl;
}
