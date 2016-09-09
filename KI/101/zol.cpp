#include <cstdio>

int n, t[500005];

bool ok(int x) {
    int ile = x, ilenow = x;
    for (int i = 1; i <= n && ile >= 0; ) {
        while (i <= n && t[i] <= ilenow)
            ilenow -= t[i], i++;
        if (t[i] > x)
            return false;
        ile--;
        ilenow = x;
    }
    return (ile >= 0);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &t[i]);
    int mi = 1, ma = 1000000000, s;
    while (mi < ma) {
        s = (mi + ma) / 2;
        if (ok(s))
            ma = s;
        else
            mi = s + 1;
    }
    printf("%d\n", mi);
}
