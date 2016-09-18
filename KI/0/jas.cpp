#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int DP[2001];
    int ost[2001];
    DP[1] = 0;
    for (int i = 2; i <= n; ++i)
        DP[i] = 100000;
    for (int i = 2; i <= n; ++i)
        for (int j = i/2; j < i; ++j)
            if (DP[j] + DP[i-j] + 1 < DP[i])
                ost[i] = i-j, DP[i] = DP[j] + DP[i-j] + 1;
    cout << DP[n] << endl;
    int tmp = n;
    while (tmp != 0) {
        cout << tmp << " ";
        tmp = ost[tmp];
    }
}
