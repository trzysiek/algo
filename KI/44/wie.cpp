#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[1000005];
int m, x0;

int powah(int a, int b) {
    long long res = 1LL;
    long long pow = a;
    while (b) {
        if (b % 2) res = (res * pow) % m;
        pow = (pow * pow) % m;
        b /= 2;
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i)
        scanf("%d", &a[i]);
    scanf("%d%d", &m, &x0);

    long long w = 0LL;
    for (int i = 0; i <= n; ++i) {
        w = (w + ((long long)a[i]) * powah(x0, i)) % m;
    }
    printf("%lld\n", (m + (w % m)) % m);
}
