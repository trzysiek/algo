#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

typedef long long LL;

const int P = 1000 * 1000 * 1000 + 7;

int n, m, a, b;
string s;
LL h[1000001];
LL pot[1000001];

LL hasz(int a, int b) {
}

bool check(int a, int b) {
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s >> m;

    pot[0] = 1;
    for (int i = 1; i < n; ++i)
        pot[i] = pot[i - 1] * P;

    h[0] = s[0];
    for (int i = 1; i < n; ++i)
        h[i] = h[i-1] * P + s[i];

    while (m--) {
        cin >> a >> b;
        if (((b - a) % 2 == 0) || !check(a, b))
            puts("NIE\n");
        else
            puts("TAK\n");
    }
}
