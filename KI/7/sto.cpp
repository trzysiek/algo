#include <cstdio>
#include <algorithm>

int n, m;
int wyn[601][601];

int main() {
    scanf("%d%d", &n, &m);
    int a, b;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            wyn[i][j] = i * j;
    while (scanf("%d%d", &a, &b) == 2) // read both a and b.
        wyn[a][b] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k < j; ++k)
                wyn[i][j] = std::min(wyn[i][j], wyn[i][k] + wyn[i][j - k]);
            for (int k = 1; k < i; ++k)
                wyn[i][j] = std::min(wyn[i][j], wyn[k][j] + wyn[i - k][j]);
        }
    }
    printf("%d\n", wyn[n][m]);
}
