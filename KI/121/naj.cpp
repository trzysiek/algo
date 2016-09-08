#include <cstdio>

int k, n, x;
int ile[1000005];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &x), ile[x]++;
    int ile_mam = 0;
    for (int i = 0; i <= 1000000; ++i) {
        ile_mam += ile[i];
        if (ile_mam >= k) {
            printf("%d\n", i);
            return 0;
        }
    }
}
